#include "lemlib/api.hpp"
#include "api.h"
extern pros::Motor lf;
extern pros::Motor lm;
extern pros::Motor lb;
extern pros::Motor rf;
extern pros::Motor rm;
extern pros::ADIDigitalOut wing1;
extern pros::ADIDigitalOut wing2;
extern float prevKp;
extern float prevKd;


extern pros::Motor rb; // port 4, red gearbox, reversed

extern pros::MotorGroup rightMotor;
extern pros::MotorGroup leftMotor;
extern pros::ADIDigitalOut wing1;
extern pros::ADIDigitalOut wing2;


extern pros::Rotation backRot;
extern pros::IMU imu;
extern pros::Motor intakeMotor;

extern lemlib::TrackingWheel horizontal;


extern lemlib::OdomSensors_t sensors ;
extern pros::ADIDigitalIn  limitSwitch;
extern pros::Motor fly_wheel;


//TODO - CHANGE TRACK WIDTH
extern lemlib::Drivetrain_t drivetrain;
// forward/backward PID
extern lemlib::ChassisController_t lateralController;
 
// turning PID
extern lemlib::ChassisController_t angularController;
extern lemlib::Chassis chassis;

extern pros::ADIDigitalOut intakeHold;