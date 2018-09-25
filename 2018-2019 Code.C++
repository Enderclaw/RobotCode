#include "robot-config.h"
vex::rotationUnits rotations = vex::rotationUnits::rev;

int main() {
	int howMany = 1;
	LeftMotor.startRotateFor(howMany, rotations);
	RightMotor.rotateFor(howMany, rotations);

	vex::task::sleep(1000);

	howMany = -2;
	LeftMotor.startRotateFor(howMany, rotations);
	RightMotor.rotateFor(howMany, rotations);
}
