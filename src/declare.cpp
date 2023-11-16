#include "main.h"

pros::Motor lf(13, pros::E_MOTOR_GEARSET_06, false); // port 1, blue gearbox, not reversed
pros::Motor lm(14, pros::E_MOTOR_GEARSET_18, false); // port 2, green gearbox, not reversed
pros::Motor lb(15, pros::E_MOTOR_GEARSET_18, false); // port 2, green gearbox, not reversed
pros::Motor rf(18, pros::E_MOTOR_GEARSET_36, true); // port 3, red gearbox, reversed
pros::Motor rm(17, pros::E_MOTOR_GEARSET_36, true); // port 3, red gearbox, reversed
pros::Motor rb(16, pros::E_MOTOR_GEARSET_36, true); // port 4, red gearbox, reversed

pros::MotorGroup rightMotor({rf,rm, rb});
pros::MotorGroup leftMotor({lf,lm, lb});

pros::Rotation backRot(7);
pros::IMU imu(8);
pros::Motor intakeMotor(10, pros::E_MOTOR_GEARSET_06, true);

lemlib::TrackingWheel horizontal(&backRot, 3.25, 2.5);


lemlib::OdomSensors_t sensors {nullptr, nullptr, &horizontal, nullptr, &imu};
pros::ADIDigitalIn  limitSwitch('A');
pros::Motor cata(9);


//TODO - CHANGE TRACK WIDTH
lemlib::Drivetrain_t drivetrain {
    &leftMotor, // left drivetrain motors
    &rightMotor, // right drivetrain motors
    10, // track width
    3.25, // wheel diameter
    360 // wheel rpm
};
// forward/backward PID
lemlib::ChassisController_t lateralController {
    8, // kP
    30, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    5 // slew rate
};
 
// turning PID
lemlib::ChassisController_t angularController {
    4, // kP
    40, // kD
    1, // smallErrorRange
    100, // smallErrorTimeout
    3, // largeErrorRange
    500, // largeErrorTimeout
    0 // slew rate
};
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);