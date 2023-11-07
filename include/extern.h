#include "lemlib/api.hpp"
/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
pros::Motor lf;
pros::Motor lm;
pros::Motor lb;
pros::Motor rf;
pros::Motor rm;

pros::Motor rb;

pros::MotorGroup rightMotor;
pros::MotorGroup leftMotor;

pros::Rotation backRot;
pros::IMU imu;

lemlib::TrackingWheel horizontal;


lemlib::OdomSensors_t sensors;


//TODO - CHANGE TRACK WIDTH
lemlib::Drivetrain_t drivetrain ;
// forward/backward PID
lemlib::ChassisController_t lateralController;
 
// turning PID
lemlib::ChassisController_t angularController;
lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);