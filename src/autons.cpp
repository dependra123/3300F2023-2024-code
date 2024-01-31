#include "main.h"

void intake(bool reverse=false){
    intakeMotor.move(reverse ? -127: 127);
}

// void wing(bool open){
//     wing1.set_value(open);
//   wing2.set_value(open);
// }

// }
// void autoTuner(){
//     //make a task that will tune the pid values
//     //Start at default vaules check for ocillations the increase kD until ocillations stop
//     //then increase kP until ocillations start again
//     //repeat until oscillations can not be stopped then set kD and kP to the last value that stopped oscillations
    
//     int count = 0; 
//     bool tuning = true;
//     bool tuned = false;
//     bool driveSetteled = true;
//     bool direction = true;
//     float nextKp = 1;
//     float nextKd = 1;
//     lemlib::Pose lastPose = chassis.getPose();
//     double lastTime = pros::millis();
//     while(tuning){
//         //move forward
//         if(driveSetteled){
//             prevKp = nextKp;
//             lateralController.kD = nextKd;
//             lateralController.kP = tuned ? nextKp : nextKp+=.5;
//             chassis.moveToPoint(0, (count % 2 == 0)? 10:0, 3000, true);
            
//             driveSetteled = false;
//         }
//         if(pros::millis() - lastTime > 100){
//             lastTime = pros::millis();
//             lemlib::Pose pose = chassis.getPose();
//             if(pose.x == lastPose.x && pose.y == lastPose.y){
//                 driveSetteled = true;
//             }
//             lastPose = pose;
//         }
//         if(pros::millis() - lastTime > 200 && chassis.getPose().x - lastPose.x < 0.1 && chassis.getPose().y - lastPose.y < 0.1){
//             if(direction){
//                 direction = false;
//             }
//             else{
//                 tuned = true;
//                 prevKd = nextKd;
//                 nextKd += .5;
//             }
//         }

        
        
//         //check for ocillations

//         count++;
        
        
        

//     }
    

// }
// int test(){
//     chassis.moveToPoint(0, 10, 100);
//     chassis.moveToPoint(0, 0, 100);
//     chassis.turnTo(0, 0, 100);
//     return 0;
    
// }

// // int closeSideQual(){
// //     intake();
// //     chassis.moveToPoint(-5, 60, 2500);
// //     pros::delay(500);
// //     intakeMotor.move(0);
// //     pros::Task openWingMiddle([=](){
// //         bool open= false;
// //         uint32_t time = pros::millis();
// //         while(!open){
            
// //             if (chassis.getPose().theta == 180 || time - pros::millis() == 1700){
// //                 wing1.set_value(true);
// //                 open = true;
// //             }

// //         }
// //     });
// //     chassis.follow("closeSide1.txt", 5000, 10);
// //     openWingMiddle.remove();
// //     intake(true);
// //     pros::delay(300);
// //     intake();
// //     wing1.set_value(false);
// //     chassis.moveToPoint(-10,23, 2000);
// //     pros::delay(300);
// //     intakeMotor.move(0);
// //     chassis.moveToPoint(-20,23, 1000);
// //     pros::delay(100);
// //     chassis.turnTo(-47, 0, 800);
// //     wing1.set_value(true);
// //     wing2.set_value(true);
// //     chassis.moveToPoint(-41, 0, 1500);
// //     wing1.set_value(false);
// //     wing2.set_value(false);
// //     chassis.turnTo(-32, 0, 1000);
// //     intake();
// //     chassis.moveToPoint(-32,0,2500);
// //     pros::delay(500);
// //     intakeMotor.move(0);



// //     return 0;
// // }

// int offAuton(){
//     intake(true);
//     intakeMotor.move(127);
//     chassis.moveToPoint(35, -13, 1000);
//     chassis.turnTo(50, -13, 1000);
//     chassis.moveToPoint(50, -13, 1000);
//     intakeMotor.move(-127);
//     pros::delay(1000);
//     intakeMotor.move(0);
//     chassis.moveToPoint(25, -13, 1000);
//     chassis.turnTo(-20, -13, 1000);
//     chassis.moveToPoint(50, -13, 1000);
//     chassis.moveToPoint(35, -13, 1000);
    
//     // intakeMotor.move(127);
//     // chassis.moveToPoint(5, 0, 1000);
//     // pros::delay(1000);
//     // intakeMotor.move(0);
//     // chassis.turnTo(35, -13, 1000);
//     // chassis.moveToPoint(35, -13, 1000);
//     // chassis.turnTo(50, -13, 1000);
//     // intakeMotor.move(-127);
//     // pros::delay(1000);
//     // intakeMotor.move(0);
//     // chassis.moveToPoint(25, -13, 1000);
//     // chassis.turnTo(-20, -13, 1000);
//     // chassis.moveToPoint(50, -13, 1000);
//     // chassis.moveToPoint(35, -13, 1000);

//     chassis.turnTo(35, -63, 1000);
//     chassis.moveToPoint(35, -63, 1000);

//     // chassis.turnTo(5, -63, 1000);
//     // intakeMotor.move(127);
//     // chassis.moveToPoint(4, -63, 1000);
//     // pros::delay(1000);
//     // intakeMotor.move(0);



//     // chassis.moveToPoint(0, 0, 5000);
//     // chassis.moveToPoint(0.722, 32.411, 5000);
//     // chassis.moveToPoint(-0.481, -13.288, 5000);
//     // wing(true);
    

//     return 0;
// }

int defAuton(){
    chassis.setPose({-36, -61, 0});
    chassis.moveToPoint(-36, -58, 1000);
    intakeMotor.move(127);
    chassis.moveToPoint(-60, -35, 1000);
    chassis.turnTo(-60, -28, 1000);
    intakeMotor.move(-127);
    pros::delay(1000);
    intakeMotor.move(0);
    chassis.moveToPoint(-60, -40, 1000, false);
    chassis.turnTo(-60, -60, 1000);
    chassis.moveToPoint(-60, -27, 1000, false);
    pros::delay(1000);
    chassis.moveToPoint(-60, -40, 1000);
    chassis.moveToPose(-25, -1, 0, 3500, {.forwards = true});
    intakeMotor.move(127);
    chassis.turnTo(-40, -60, 750);
    chassis.moveToPoint(-100, -58, 1000);
    pros::delay(1000);
    chassis.turnTo(0, -60, 750);
    intakeMotor.move(-127);
    chassis.moveToPoint(-7, -60, 1000, true, 100);

    /*chassis.turnTo(-24, -35, 1000);
    chassis.moveToPoint(-24, -35, 1000);
    chassis.turnTo(-24, -1, 1000);
    intakeMotor.move(127);
    chassis.moveToPoint(-24, -7, 1000);
    pros::delay(500);
    intakeMotor.move(0);
    chassis.turnTo(-10, -20, 1000);
    chassis.moveToPoint(-10, -20, 1000);
    chassis.turnTo(15, -20, 1000);
    intakeMotor.move(-127);
    pros::delay(2000);
    intakeMotor.move(0);*/


    
//     /*
//     chassis.moveToPoint(-60, 0, 2000);
//     chassis.turnTo(-10, -30, 2000);
//     chassis.moveToPoint(-10, -30, 2000);
//     chassis.turnTo(25, -30, 2000);
//     intakeMotor.move(-127);
//     pros::delay(2000);
//     intakeMotor.move(0);
//     chassis.turnTo(-10, 0, 2000);
//     intakeMotor.move(127);
//     chassis.moveToPoint(-10, 0, 2000);
//     chassis.turnTo(30, 0, 2000);
//     intakeMotor.move(-127);
//     pros::delay(2000);
//     intakeMotor.move(0);
//     */

    
    return 0;
}
// int testOffAuton(){
//     intake();
//     chassis.moveToPoint(3, 60, 5000, 300);
    
//     chassis.turnTo(50, -60, 5000);
//     chassis.moveToPoint(50, -60, 5000, 300);
    
//     wing(true);
//     intake(true);
//     chassis.moveToPoint(62, -45, 5000,120);
//     wing(false);
    
//     chassis.moveToPoint(62, -25, 5000,250);
    


//     return 0;
// }

int skills(){
    chassis.setPose(-48,-55,315);
    intake();
    chassis.moveToPoint(-62.5,-40, 1000);
    intake(true);
    chassis.moveToPoint(-63, -26, 1500);
    chassis.moveToPose(-67, -45, 70, 1300, {.forwards=false});
    intakeMotor.move(0);
    fly_wheel.move(-127);
    drivetrain.leftMotors->set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
    drivetrain.rightMotors->set_brake_modes(pros::E_MOTOR_BRAKE_HOLD);
    drivetrain.leftMotors->brake();
    drivetrain.rightMotors->brake();
    
    pros::delay(30000);
    drivetrain.leftMotors->set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
    drivetrain.rightMotors->set_brake_modes(pros::E_MOTOR_BRAKE_COAST);
    fly_wheel.move(0);
    chassis.moveToPoint(-28,-60,1000);
    chassis.moveToPose(57,-20,0,3500);
    chassis.waitUntilDone();
    chassis.setPose(57,-22,0);
    //add wings here
    chassis.moveToPoint(57, -35,1000, false);
    chassis.moveToPoint(10,-35,1000);
    chassis.moveToPoint(48, -8, 1000);

    chassis.moveToPoint(10,0,1000,false);
    chassis.turnTo(48,0, 1000);
    chassis.moveToPoint(48,0, 2000, true, 90);
        //open wings

    chassis.moveToPoint(5, 16, 1000);
    chassis.moveToPose(48, 10, 90, 2000);
    






    return 0;
}
// ASSET(sixBallSidePart1_txt);
// void offenciveAuton(){
//     chassis.setPose(10,-60,90);
//     //grab triball under elvation
//     chassis.moveToPointPoint(0,-60,1000);
//     intake();
//     chassis.waitUntilDone();
//     chassis.follow(sixBallSidePart1_txt, 6, 5000);
//     chassis.waitUntil(50);
//     wing(true);
//     chassis.waitUntil(60);
//     wing(false);
    


// }
// int test(){
//     chassis.setPose(0,0,0);
//     chassis.moveToPointPoint(0, 10, 3000);
//     chassis.moveToPointPoint(0, 20, 3000, false);
//     chassis.moveToPointPose(0, 0, 90, 5000);

//     return 0;
// }

int sixBallAuton(){
    //pick up ball from under elvation
    chassis.setPose(24,-58,270);
    intake();
    chassis.moveToPoint(5, -60, 1000);
    

    //boomarang to beside net
    chassis.moveToPose(62,-35, 0, 3000, {.forwards = true});
    chassis.waitUntil(50);
    //get from matchload
    //wing(true);
    chassis.waitUntil(60);
    //wing(false);
    //outtake and push into net
    intake(true);
    chassis.moveToPoint(60,-30, 700);
    chassis.moveToPoint(58, -45, 1000, false);
    intake();
    chassis.moveToPoint(4,-24, 700);
    //line up and go for the triball not in middle
    chassis.turnTo(12, -24, 750);
    chassis.moveToPoint(12,-24, 200, false);
    chassis.waitUntilDone();
    chassis.turnTo(60,0,750);
    //out take infront of the net
    intake(true);
    pros::delay(500);
    //get the top middle triball and push all into the net
    intake();
    chassis.moveToPoint(9,-7,750);
    chassis.moveToPoint(40,0, 2000);
    intake(true);
    chassis.waitUntil(10);
    //wing(true);



    return 0;




}
