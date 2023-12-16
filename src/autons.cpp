#include "main.h"

void intake(bool reverse=false){
    intakeMotor.move(reverse ? -127: 127);
}
void driveTask(){
    chassis.moveTo(0, 10, 3000);
}
void wing(bool open){
    wing1.set_value(open);
    wing2.set_value(open);


}
void autoTuner(){
    //make a task that will tune the pid values
    //Start at default vaules check for ocillations the increase kD until ocillations stop
    //then increase kP until ocillations start again
    //repeat until oscillations can not be stopped then set kD and kP to the last value that stopped oscillations
    
    int count = 0; 
    bool tuning = true;
    bool tuned = false;
    bool driveSetteled = true;
    bool direction = true;
    float nextKp = 1;
    float nextKd = 1;
    lemlib::Pose lastPose = chassis.getPose();
    double lastTime = pros::millis();
    while(tuning){
        //move forward
        if(driveSetteled){
            prevKp = nextKp;
            lateralController.kD = nextKd;
            lateralController.kP = tuned ? nextKp : nextKp+=.5;
            chassis.moveTo(0, (count % 2 == 0)? 10:0, 3000, true);
            
            driveSetteled = false;
        }
        if(pros::millis() - lastTime > 100){
            lastTime = pros::millis();
            lemlib::Pose pose = chassis.getPose();
            if(pose.x == lastPose.x && pose.y == lastPose.y){
                driveSetteled = true;
            }
            lastPose = pose;
        }
        if(pros::millis() - lastTime > 200 && chassis.getPose().x - lastPose.x < 0.1 && chassis.getPose().y - lastPose.y < 0.1){
            if(direction){
                direction = false;
            }
            else{
                tuned = true;
                prevKd = nextKd;
                nextKd += .5;
            }
        }

        
        
        //check for ocillations

        count++;
        
        
        

    }
    

}
int test(){
    chassis.moveTo(0, 10, 100);
    chassis.moveTo(0, 0, 100);
    chassis.turnTo(0, 0, 100);
    return 0;
    
}

// int closeSideQual(){
//     intake();
//     chassis.moveTo(-5, 60, 2500);
//     pros::delay(500);
//     intakeMotor.move(0);
//     pros::Task openWingMiddle([=](){
//         bool open= false;
//         uint32_t time = pros::millis();
//         while(!open){
            
//             if (chassis.getPose().theta == 180 || time - pros::millis() == 1700){
//                 wing1.set_value(true);
//                 open = true;
//             }

//         }
//     });
//     chassis.follow("closeSide1.txt", 5000, 10);
//     openWingMiddle.remove();
//     intake(true);
//     pros::delay(300);
//     intake();
//     wing1.set_value(false);
//     chassis.moveTo(-10,23, 2000);
//     pros::delay(300);
//     intakeMotor.move(0);
//     chassis.moveTo(-20,23, 1000);
//     pros::delay(100);
//     chassis.turnTo(-47, 0, 800);
//     wing1.set_value(true);
//     wing2.set_value(true);
//     chassis.moveTo(-41, 0, 1500);
//     wing1.set_value(false);
//     wing2.set_value(false);
//     chassis.turnTo(-32, 0, 1000);
//     intake();
//     chassis.moveTo(-32,0,2500);
//     pros::delay(500);
//     intakeMotor.move(0);



//     return 0;
// }

int offAuton(){
    // intake(true);
    // intakeMotor.move(127);
    // chassis.moveTo(35, -13, 2000);
    // chassis.turnTo(50, -13, 2000);
    // intakeMotor.move(-127);
    // pros::delay(1000);
    // intakeMotor.move(0);
    // chassis.turnTo(35, -63, 2000);
    // chassis.moveTo(35, -63, 2000);
    // chassis.turnTo(5, -63, 2000);
    // chassis.moveTo(5, -63, 2000);
    chassis.moveTo(0, 0, 5000);
    chassis.moveTo(0.722, 32.411, 5000);
    chassis.moveTo(-0.481, -13.288, 5000);
    wing(true);
    

    return 0;
}

int defAuton(){
    intake(true);
    intakeMotor.move(127);
    chassis.turnTo(-146, -114, 2000);
    chassis.moveTo(-146, -114, 2000);
    chassis.turnTo(-146, -63, 2000);
    intakeMotor.move(-127);
    pros::delay(2000);
    intakeMotor.move(0);
    chassis.moveTo(-146, -63, 2000);
    chassis.moveTo(-146, -90, 2000);
    chassis.turnTo(-60, -90, 2000);
    chassis.moveTo(-60, -90, 2000);
    chassis.turnTo(-60, 0, 2000);
    intakeMotor.move(127);
    chassis.moveTo(-60, 0, 2000);
    chassis.turnTo(-10, -30, 2000);
    chassis.moveTo(-10, -30, 2000);
    chassis.turnTo(25, -30, 2000);
    intakeMotor.move(-127);
    pros::delay(2000);
    intakeMotor.move(0);
    chassis.turnTo(-10, 0, 2000);
    intakeMotor.move(127);
    chassis.moveTo(-10, 0, 2000);
    chassis.turnTo(30, 0, 2000);
    intakeMotor.move(-127);
    pros::delay(2000);
    intakeMotor.move(0);

    
    return 0;
}
int testOffAuton(){
    intake();
    chassis.moveTo(3, 60, 5000, 300);
    
    chassis.turnTo(50, -60, 5000);
    chassis.moveTo(50, -60, 5000, 300);
    
    wing(true);
    intake(true);
    chassis.moveTo(62, -45, 5000,120);
    wing(false);
    
    chassis.moveTo(62, -25, 5000,250);
    


    return 0;
}

int skills(){
    fw.move(127);
    //  PUT THE SET POS INTO INITLIZE
    chassis.setPose(-36, -60, 90);

    //Go to matchload and shoot triballs
    chassis.moveTo(-55,-50,1500, 360);
    chassis.turnTo(45, 0, 1500);
    pros::delay(25000);

    //push alliacne triball into net
    chassis.turnTo(-60,-25, 1500, true);
    chassis.moveTo(-60,-25,1500, 360);
    chassis.moveTo(-25, -60,360);
    
    //go to other side
    chassis.turnTo(36, -60, 1500, true);
    chassis.moveTo(36, -60, 1500,300);

    //push on side
    chassis.turnTo(60,-25, 1500, true);
    chassis.moveTo(60,-25,1500, 360);

    //push from front
    chassis.moveTo(48,-48, 1500, 360);
    chassis.moveTo(10,10,1500,300);
    chassis.turnTo(45,0,750,true);
    wing(true);
    chassis.moveTo(45,0,750);
    wing(false);

    //push from side
    chassis.moveTo(10,35,1700, 360);
    wing(true);
    chassis.moveTo(40,12,750);
    wing(false);









    

    return 0;
}