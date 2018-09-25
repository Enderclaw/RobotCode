#include "robot-config.h"
vex::rotationUnits rotations = vex::rotationUnits::rev;

int main() {
	int howMany = 2; //move forward
	LeftMotor.startRotateFor(howMany, rotations);
	RightMotor.rotateFor(howMany, rotations);

	vex::task::sleep(1000);

	howMany = -2; //move back
	LeftMotor.startRotateFor(howMany, rotations);
	RightMotor.rotateFor(howMany, rotations);
	
	vex::task::sleep(1000);
	
	float revsPerClawbot90Turn = 1.7;
	LeftMotor.startRotateFor(-1 * revsPerClawbot90Turn, revolutions); //left turn
	RightMotor.rotateFor(revsPerClawbot90Turn, revolutions);
	
	vex::task::sleep(1000);
	
	LeftMotor.startRotateFor(2 * revsPerClawbot90Turn, revolutions); //right turn
	RightMotor.rotateFor(-2 * revsPerClawbot90Turn, revolutions);
}
