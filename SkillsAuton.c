#pragma config(Motor,  port1,           FDL,           tmotorVex393_HBridge, openLoop, reversed, driveLeft)
#pragma config(Motor,  port2,           BDL,           tmotorVex393_MC29, openLoop, reversed, driveLeft)
#pragma config(Motor,  port3,           LLF,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           LLB,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           NDL,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           NDR,           tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           RLF,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port8,           RLB,           tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port9,           BDR,           tmotorVex393_MC29, openLoop, driveRight)
#pragma config(Motor,  port10,          FDR,           tmotorVex393_HBridge, openLoop, driveRight)
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
	//motor[LLF] = 127;
	//motor[LLB] = 127;
	//motor[RLF] = 127;
	//motor[RLB] = 127;

	motor[FDL] = -127;
	motor[FDR] = -127;
	motor[BDL] = -127;
	motor[BDR] = -127;
	motor[NDL] = -127;
	motor[NDR] = -127;
	wait1Msec(6000);

	motor[FDL] = 0;
	motor[FDR] = 0;
	motor[BDL] = 0;
	motor[BDR] = 0;
	motor[NDL] = 0;
	motor[NDR] = 0;
	wait1Msec(7000);

	/*motor[FDL] = 127;
	motor[FDR] = 127;
	motor[BDL] = 127;
	motor[BDR] = 127;

	motor[LLF] = -127;
	motor[LLB] = -127;
	motor[RLF] = -127;
	motor[RLB] = -127;
	wait1Msec(1500);

	motor[LLF] = 0;
	motor[LLB] = 0;
	motor[RLF] = 0;
	motor[RLB] = 0;
	wait1Msec(4500);


	motor[FDL] = -127;
	motor[FDR] = -127;
	motor[BDL] = -127;
	motor[BDR] = -127;
	wait1Msec(1000);

	motor[FDL] = -127;
	motor[FDR] = -127;
	motor[BDL] = 127;
	motor[BDR] = 127;
	wait1Msec(800);

	motor[FDL] = 127;
	motor[FDR] = 127;
	motor[BDL] = 127;
	motor[BDR] = 127;
	wait1Msec(1200);

	motor[FDL] = -127;
	motor[FDR] = -127;
	motor[BDL] = 127;
	motor[BDR] = 127;
	wait1Msec(800);

	motor[FDL] = 127;
	motor[FDR] = 127;
	motor[BDL] = 127;
	motor[BDR] = 127;
	wait1Msec(5000);

	motor[FDL] = 0;
	motor[FDR] = 0;
	motor[BDL] = 0;
	motor[BDR] = 0;*/
}

task usercontrol()
{
	while (true)
	{
		motor[FDL] = vexRT[Ch3];
		motor[BDL] = vexRT[Ch3];
		motor[NDL] = vexRT[Ch3];

		motor[NDR] = vexRT[Ch3];
		motor[FDR] = vexRT[Ch2];
		motor[BDR] = vexRT[Ch2];

		if(vexRT[Btn5U] == 1)
		{
			motor[LLF] = 127;
			motor[LLB] = 127;
			motor[RLF] = 127;
			motor[RLB] = 127;
		}

		else if(vexRT[Btn5D] == 1)
		{
			motor[LLF] = -127;
			motor[LLB] = -127;
			motor[RLF] = -127;
			motor[RLB] = -127;
		}

		else
		{
			motor[LLF] = 0;
			motor[LLB] = 0;
			motor[RLF] = 0;
			motor[RLB] = 0;
		}

		/*if (vexRT[Btn8D]) {
			motor[FDL] = 127;
			motor[FDR] = 117;		//Drive Forward
			motor[BDL] = 127;
			motor[BDR] = 117;

			motor[LLF] = -127;
			motor[LLB] = -127;		//Initiate Mogol
			motor[RLF] = -127;
			motor[RLB] = -127;
			wait1Msec(1500);

			motor[LLF] = 0;
			motor[LLB] = 0;		//Stop Mogol
			motor[RLF] = 0;
			motor[RLB] = 0;
			wait1Msec(1000);
			//Mobile Goal is in the lift as of now.
			motor[LLF] = 127;
			motor[LLB] = 127;		//MoveMogol back
			motor[RLF] = 127;
			motor[RLB] = 127;
			wait1Msec(1000);

			motor[FDL] = 127;
			motor[FDR] = -127;		//Stop Drive
			motor[BDL] = 127;
			motor[BDR] = -127;

			motor[LLF] = 0;
			motor[LLB] = 0;		//Halt Mogol
			motor[RLF] = 0;
			motor[RLB] = 0;
			wait1Msec(1000);

			motor[LLF] = -127;
			motor[LLB] = -127;		//Initiate Mogol
			motor[RLF] = -127;
			motor[RLB] = -127;
			wait1Msec(1000);

			motor[LLF] = 0;
			motor[LLB] = 0;		 //Stop Mogo
			motor[RLF] = 0;
			motor[RLB] = 0;

			motor[FDL] = -127;
			motor[FDR] = -127;		//Reverse
			motor[BDL] = -127;
			motor[BDR] = -127;
			wait1Msec(1000);

			motor[FDL] = 0;
			motor[FDR] = 0;		//Stop Drive
			motor[BDL] = 0;
			motor[BDR] = 0;
		}*/
	}
}
