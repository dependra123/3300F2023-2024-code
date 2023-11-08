
#include "main.h"
void intake(bool reverse=false){
    intakeMotor.move(reverse ? -127: 127);
}


int closeSideQual(){
    intake();
    chassis.moveTo(-5, 60, 2500);
    pros::delay(500);
    intakeMotor.move(0);
    pros::Task openWingMiddle([=](){
        bool open= false;
        uint32_t time = pros::millis();
        while(!open){
            
            if (chassis.getPose().theta == 180 || time - pros::millis() == 1700){
                wing1.set_value(true);
                open = true;
            }

        }
    });
    chassis.follow("closeSide1.txt", 5000, 10);
    openWingMiddle.remove();
    intake(true);
    pros::delay(300);
    intake();
    wing1.set_value(false);
    chassis.moveTo(-10,23, 2000);
    pros::delay(300);
    intakeMotor.move(0);
    chassis.moveTo(-20,23, 1000);
    chassis.turnTo(-47, 0, 800);
    wing1.set_value(true);
    wing2.set_value(true);
    chassis.moveTo(-41, 0, 1500);
    wing1.set_value(false);
    wing2.set_value(false);
    chassis.turnTo(-32, 0, 1000);
    intake();
    chassis.moveTo(-32,0,2500);









    





}