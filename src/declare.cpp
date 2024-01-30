#include "main.h"

float prevKp = 0;
float prevKd = 0;
pros::Motor rf(5, pros::E_MOTOR_GEARSET_06, true); // port 1, blue gearbox, not reversed
pros::Motor rm(2, pros::E_MOTOR_GEARSET_06, false); // port 2, green gearbox, reversed
pros::Motor rb(3, pros::E_MOTOR_GEARSET_06, false); // port 2, green gearbox, not reversed
pros::Motor lf(6, pros::E_MOTOR_GEARSET_06, false); // port 3, red gearbox, reversedno
pros::Motor lm(7, pros::E_MOTOR_GEARSET_06, true); // port 3, red gearbox, not reversed
pros::Motor lb(9, pros::E_MOTOR_GEARSET_06, true); // port 4, red gearbox, reversed

pros::MotorGroup rightMotor({rf,rm, rb});
pros::MotorGroup leftMotor({lf,lm, lb});

// pros::Rotation backRot(7);
pros::IMU imu(19);
pros::Motor intakeMotor(1, pros::E_MOTOR_GEARSET_06, true);
// pros::ADIDigitalOut intakeHold('G');
// pros::ADIDigitalOut wing1('A');

//lemlib::TrackingWheel horizontal(&backRot, 3.25, 2.5);


lemlib::OdomSensors sensors {nullptr, nullptr, nullptr, nullptr, &imu};
// pros::ADIDigitalIn  limitSwitch('H');
pros::Motor fly_wheel(10);


//TODO - CHANGE TRACK WIDTH
lemlib::Drivetrain drivetrain (&leftMotor, // left drivetrain motors
    &rightMotor, // right drivetrain motors
    13, // track width
    lemlib::Omniwheel::NEW_275, // wheel diameter
    450, // wheel rpm
    5
);
// forward/backward PID
// lateral motion controller
lemlib::ControllerSettings linearController(10, // proportional gain (kP)
                                            0, // integral gain (kI)
                                            3, // derivative gain (kD)
                                            3, // anti windup
                                            1, // small error range, in inches
                                            100, // small error range timeout, in milliseconds
                                            3, // large error range, in inches
                                            500, // large error range timeout, in milliseconds
                                            20 // maximum acceleration (slew)
);

// angular motion controller
lemlib::ControllerSettings angularController(2, // proportional gain (kP)
                                             0, // integral gain (kI)
                                             10, // derivative gain (kD)
                                             3, // anti windup
                                             1, // small error range, in degrees  
                                             100, // small error range timeout, in milliseconds
                                             3, // large error range, in degrees
                                             500, // large error range timeout, in milliseconds
                                             0 // maximum acceleration (slew)
);
lemlib::Chassis chassis(drivetrain, linearController, angularController, sensors);