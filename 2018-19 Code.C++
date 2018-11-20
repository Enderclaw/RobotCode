int main() {

	while(true) { //Tank Control
		LeftDrive.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);  //(Axis3+Axis4)/2
		RightDrive.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct); //(Axis3-Axis4)/2
		vex::task::sleep(20); 
    }
	
//Use these variables to set the speed of the arm and claw.
	int LiftSpeedPCT = 50;
	int CapSpeedPCT = 50;
	int FlySpeedPCT = 100;

	while(true) { //Claw Control
		if(Controller1.ButtonL1.pressing()) {
			LeftLift.spin(directionType::fwd, LiftSpeedPCT, velocityUnits::pct);
			RightLift.spin(directionType::fwd, LiftSpeedPCT, velocityUnits::pct);
		}
		else if(Controller1.ButtonL2.pressing()) {
			LeftLift.spin(directionType::rev, LiftSpeedPCT, velocityUnits::pct);
			RightLift.spin(directionType::rev, LiftSpeedPCT, velocityUnits::pct);
		}
		else {
			LeftLift.stop(brakeType::brake);
			RightLift.stop(brakeType::brake);
		}
		
		if(Controller1.ButtonR1.pressing()) { //Cap Control
			CapMotor.spin(directionType::fwd, CapSpeedPCT, velocityUnits::pct);
		}
		else if(Controller1.ButtonR2.pressing()) {
			CapMotor.spin(directionType::rev, CapSpeedPCT, velocityUnits::pct);
		}
		else {
			CapMotor.stop(brakeType::brake);
		}
		
		if(Controller1.ButtonA.pressing()) {
			FlyMotor.spin(directionType::fwd, FlySpeedPCT, velocityUnits::pct);
		}
		if(Controller1.ButtonY.pressing()) {
			FlyMotor.spin(directionType::rev, FlySpeedPCT, velocityUnits::pct);
		}
		else {
			FlyMotor.stop(brakeType::brake);
			
			

        task::sleep(20);
    }
}
