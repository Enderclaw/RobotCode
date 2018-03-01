#pragma config(Motor,  port1,           FDL,           tmotorVex393_HBridge, openLoop, driveLeft)
#pragma config(Motor,  port2,           BDL,           tmotorVex393_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port3,           LLT,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           LLB,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           RLT,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           RLB,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           Claw,          tmotorServoStandard, openLoop)
#pragma config(Motor,  port8,           Lift3,         tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           BDR,           tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port10,          FDR,           tmotorVex393_HBridge, openLoop, reversed, driveRight)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

void pre_auton()
{
	bStopTasksBetweenModes = true;
}

task autonomous()
{
	motor[FDL] = 127; //drive forward
	motor[BDL] = 127;
	motor[FDR] = 127;
	motor[BDR] = 127;
	wait1Msec(2500);

	motor[FDL] = 0; //stop
	motor[BDL] = 0;
	motor[FDR] = 0;
	motor[BDR] = 0;
	wait1Msec(2500);

	motor[LLT] = 127; //raise claw
	motor[LLB] = 127;
	motor[RLT] = 127;
	motor[RLB] = 127;
	motor[Lift3] = 127;
	wait1Msec(1000);

	motor[LLT] = 0; //Stop lift
	motor[LLB] = 0;
	motor[RLT] = 0;
	motor[RLB] = 0;
	motor[Lift3] = 0;
	wait1Msec(1000);

	motor[Claw] = 100; //Open claw
	wait1Msec(1000);

	motor[Claw] = 0;
	wait1Msec(1000);
}

task usercontrol()
{
	while (true)
	{
		motor[FDL] = -vexRT[Ch3];
		motor[BDL] = -vexRT[Ch3];

		motor[FDR] = -vexRT[Ch2];
		motor[BDR] = -vexRT[Ch2];

		if(vexRT[Btn5U] == 1)
		{
			motor[LLT] = 127;
			motor[LLB] = 127;
			motor[RLT] = 127;
			motor[RLB] = 127;
			motor[Lift3] = 1127;
		}

		else if(vexRT[Btn5D] == 1)
		{
			motor[LLT] = -127;
			motor[LLB] = -127;
			motor[RLT] = -127;
			motor[RLB] = -127;
			motor[Lift3] = -127;
		}

		else
		{
			motor[LLT] = 0;
			motor[LLB] = 0;
			motor[RLT] = 0;
			motor[RLB] = 0;
			motor[Lift3] = 0;
		}

		if(vexRT[Btn6U] == 1)
		{
			motor[Claw] = 127;
		}

		else if(vexRT[Btn6D] == 1)
		{
			motor[Claw] = -127;
		}

		else
		{
			motor[Claw] = 0;
		}
	}
}
