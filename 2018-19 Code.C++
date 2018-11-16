#include "robot-config.h"
using namespace vex;
vex::brain Brain;
vex::rotationUnits rotations = vex::rotationUnits::rev;
vex::motor LeftMotor (vex::PORT1, vex::gearSetting::ratio18_1, false);
vex::motor RightMotor (vex::PORT10, vex::gearSetting::ratio18_1, true);
vex::motor ClawMotor (vex::PORT3, vex::gearSetting::ratio18_1, true);
vex::motor ArmMotor (vex::PORT8, vex::gearSetting::ratio18_1, true);

int main() {

	while(true) { //Tank Control
		LeftMotor.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);  //(Axis3+Axis4)/2
		RightMotor.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct); //(Axis3-Axis4)/2
		vex::task::sleep(20); 
    }
	
//Use these variables to set the speed of the arm and claw.
	int armSpeedPCT = 50;
	int clawSpeedPCT = 50;

	while(true) { //Claw Control
		if(Controller1.ButtonUp.pressing()) {
			ArmMotor.spin(directionType::fwd, armSpeedPCT, velocityUnits::pct);
		}
		else if(Controller1.ButtonDown.pressing()) {
			ArmMotor.spin(directionType::rev, armSpeedPCT, velocityUnits::pct);
		}
		else {
			ArmMotor.stop(brakeType::brake);
		}
		
		if(Controller1.ButtonA.pressing()) {
			ClawMotor.spin(directionType::fwd, clawSpeedPCT, velocityUnits::pct);
		}
		else if(Controller1.ButtonY.pressing()) {
			ClawMotor.spin(directionType::rev, clawSpeedPCT, velocityUnits::pct);
		}
		else {
			ClawMotor.stop(brakeType::brake);
		}

        task::sleep(20);
    }
}
