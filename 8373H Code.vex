```css
#include "robot-config.h"
/*---------------------------------------------------------------------------*/
/*                                                                           */
/*        Description: Competition template for VCS VEX V5                   */
/*                                                                           */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton( void ) {
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous( void ) {
 //Use these variables to set the speed of the arm and claw.
	int LiftSpeedPCT = 100;
	int FlySpeedPCT = 100;
    
 LeftFly.spin(directionType::fwd, FlySpeedPCT, velocityUnits::pct);
 RightFly.spin(directionType::fwd, FlySpeedPCT, velocityUnits::pct);
 
 BallIntake.spin(directionType::fwd, LiftSpeedPCT, velocityUnits::pct);
    vex::task::sleep(200);
}

/*----------------------------------------------------------------------------*/
/*                                                                            */
/*                              User Control Task                             */
/*                                                                            */
/*  This task is used to control your robot during the user control phase of  */
/*  a VEX Competition.                                                        */
/*                                                                            */
/*  You must modify the code to add your own robot specific commands here.    */
/*----------------------------------------------------------------------------*/

void usercontrol( void ) {
  // User control code here, inside the loop
  while (1){
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo 
    // values based on feedback from the joysticks.
    int LiftSpeedPCT = 100;
	int CapSpeedPCT = 100;
	int FlySpeedPCT = 100;
      
      LeftDrive.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
      RightDrive.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
      
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
			RightFly.stop(brakeType::brake);
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

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to 
    // update your motors, etc.
    // ........................................................................
 
    vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources. 
  }
//
// Main will set up the competition functions and callbacks.
//
int main() {
    
    //Run the pre-autonomous function. 
    pre_auton();
    
    //Set up callbacks for autonomous and driver control periods.
    Competition.autonomous( autonomous );
    Competition.drivercontrol( usercontrol );
 
 }
```
