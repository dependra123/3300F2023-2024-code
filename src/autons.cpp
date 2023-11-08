
#include "main.h"
void intake(bool reverse=false){
    intakeMotor.move(reverse ? -127: 127);

}
int closeSideQual(){
    chassis.moveTo(1.75, 2, 2000);
    chassis.turnTo(2,0,1000);
    wing1.set_value(true);
    chassis.moveTo(2.2,.5, 1500);
    chassis.turnTo(.5,12,1000);
    chassis.moveTo(3,.5, 700);
    wing1.set_value(false);
    




}