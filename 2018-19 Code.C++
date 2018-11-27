
int main() {

	while(true) { //Tank Control
		LeftDrive.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);  //(Axis3+Axis4)/2
		RightDrive.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct); //(Axis3-Axis4)/2
		vex::task::sleep(200); 
	}
	
//Use these variables to set the speed of the arm and claw.
	int LiftSpeedPCT = 100;
	int CapSpeedPCT = 100;
	int FlySpeedPCT = 100;

	while(true) { 
		if(Controller1.ButtonL1.pressing()) { //Lift Deploy
			LeftLift.spin(directionType::fwd, LiftSpeedPCT, velocityUnits::pct);
			RightLift.spin(directionType::fwd, LiftSpeedPCT, velocityUnits::pct);
		}
		else if(Controller1.ButtonL2.pressing()) { //Lift Retract
			LeftLift.spin(directionType::rev, LiftSpeedPCT, velocityUnits::pct);
			RightLift.spin(directionType::rev, LiftSpeedPCT, velocityUnits::pct);
		}
		else {
			LeftLift.stop(brakeType::brake);
			RightLift.stop(brakeType::brake);
		}
		
		if(Controller1.ButtonR1.pressing()) { //Cap Forward
			CapFlip.spin(directionType::fwd, CapSpeedPCT, velocityUnits::pct);
		}
		else if(Controller1.ButtonR2.pressing()) { //Cap Backward
			CapFlip.spin(directionType::rev, CapSpeedPCT, velocityUnits::pct);
		}
		else {
			CapFlip.stop(brakeType::brake);
		}
		
		if(Controller1.ButtonA.pressing()) { //Flywheel Forward
			LeftFly.spin(directionType::fwd, FlySpeedPCT, velocityUnits::pct);
			RightFly.spin(directionType::fwd, FlySpeedPCT, velocityUnits::pct);
		}
		else if(Controller1.ButtonY.pressing()) { //Flywheel Backward
			LeftFly.spin(directionType::rev, FlySpeedPCT, velocityUnits::pct);
			RightFly.spin(directionType::rev, FlySpeedPCT, velocityUnits::pct);
		}
		else {
			LeftFly.stop(brakeType::brake);
			RightFLy.stop(brakeType::brake);
		}
			
		if(Controller1.ButtonUp.pressing()) { //Ball Intake Forward
			BallIntake.spin(directionType::fwd, CapSpeedPCT, velocityUnits::pct);
		}	
		else if(Controller1.ButtonDown.pressing()) { //Ball Intake Backward
			BallIntake.spin(directionType::rev, CapSpeedPCT, velocityUnits::pct);
		}
		else {
			BallIntake.stop(brakeType::brake);
		}

		
        task::sleep(200);
    }
}
