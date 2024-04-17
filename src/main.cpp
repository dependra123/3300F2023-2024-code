#include "main.h"
#include "autoSelect/selection.h"
#include "lemlib/api.hpp"



 

//  void cata_function() {
//     // loop forever
//     //cata.set_brake_mode(MOTOR_BRAKE_HOLD);
//     while (true) {
//         if (limitSwitch.get_value() == 0)
//             cata.move(127);
//         else
//             cata.move(0);
//         pros::delay(10);
//     }
// }

/**
 * Runs initializatioffAutonon code. This occurs as soon as the program is started.
 *lib/api.hpp"
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize(); // initialize brain screen
    //  selector::init();
    chassis.calibrate(); // calibrate the chassis
    //chassis.setPose({35, -63, 0}); // offensive starting position
    //chassis.setPose({35, -63, 0}); // defensive starting position
    intakeLift.set_value(false);
    
  }

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be tstopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    sixBallAuton();
    // if(selector::auton == 1){
    //     defAuton();
    // }
    // if(selector::auton == 2){
    //     sixBallAuton();
    // }
    // if(selector::auton == 0){
    //     skills();
    // }
    // if(selector::auton == -1){
    //     defAuton();
    // }
    // if(selector::auton == -2){
    //     sixBallAuton();
    // }
    // skills();


	

}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
float driveCurve(float input, float scale) {
    if (scale != 0) {
        return (powf(2.718, -(scale / 10)) + powf(2.718, (fabs(input) - 127) / 10) * (1 - powf(2.718, -(scale / 10)))) *
               input;
    }
    return input;
}


void arcade(int throttle, int turn, float curveGain) {
    int leftPower = driveCurve(throttle + turn, curveGain);
    int rightPower = driveCurve(throttle - turn, curveGain);
    drivetrain.leftMotors->move(leftPower);
    drivetrain.rightMotors->move(rightPower);
}
void opcontrol() {
    winPt.set_value(true);
    pros::Controller master(pros::E_CONTROLLER_MASTER);
    bool wingOpen = false;
    bool hangToggle =false;
    bool intakeUp = false;
    while(true){
        // wing1.set_value(wingOpen);

        chassis.arcade(master.get_analog(ANALOG_LEFT_Y), master.get_analog(ANALOG_RIGHT_X), 5);
        if(master.get_digital(DIGITAL_L1)){
            intakeMotor.move(127);

        }
        else if(master.get_digital(DIGITAL_R1)){
            intakeMotor.move(-127);
        }
        else{
            intakeMotor.move(0);
        }
        if (master.get_digital_new_press(DIGITAL_R2)){
            intakeUp=!intakeUp;
        }
        // else if(master.get_digital(DIGITAL_R2))
        //     fly_wheel.move(-120);
        // else if(master.get_digital(DIGITAL_RIGHT))
        //     fly_wheel.move(100);
         

        if (master.get_digital_new_press(DIGITAL_Y))
            wingOpen = !wingOpen;

        if(master.get_digital_new_press(DIGITAL_X)){
            hangToggle = !hangToggle;
        }
        intakeLift.set_value(intakeUp);
        wing1.set_value(wingOpen);
        wing2.set_value(wingOpen);
        
        // if(master.get_digital_new_press(DIGITAL_DOWN)) wingOpen = !wingOpen;

        pros::delay(10);
        
    }
}
