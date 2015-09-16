#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  armEncoder,     sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  intakeEncoder,  sensorQuadEncoder)
#pragma config(Sensor, dgtl11, leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           rightBack,     tmotorVex393, openLoop)
#pragma config(Motor,  port2,           rightFront,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           armRight1,     tmotorVex393, openLoop)
#pragma config(Motor,  port4,           armRight2,     tmotorVex393, openLoop)
#pragma config(Motor,  port5,           intake1,       tmotorVex393, openLoop)
#pragma config(Motor,  port6,           intake2,       tmotorVex393, openLoop)
#pragma config(Motor,  port7,           armLeft2,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           armLeft1,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           leftFront,     tmotorVex393, openLoop)
#pragma config(Motor,  port10,          leftBack,      tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void forward(int value){
	while(SensorValue[rightEncoder] < value){
		motor[rightBack] = 127;
		motor[rightFront] = 127;
		motor[leftBack] = 127;
		motor[leftFront] = 127;
	}
		motor[rightBack] = 0;
		motor[rightFront] = 0;
		motor[leftBack] = 0;
		motor[leftFront] = 0;
		SensorValue[rightEncoder] = 0;
		SensorValue[leftEncoder] = 0;
}
void forwardSpeed(int value, int speed){
	while(SensorValue[rightEncoder] < value){
		motor[rightBack] = speed;
		motor[rightFront] = speed;
		motor[leftBack] = speed;
		motor[leftFront] = speed;
	}
		motor[rightBack] = 0;
		motor[rightFront] = 0;
		motor[leftBack] = 0;
		motor[leftFront] = 0;
		SensorValue[rightEncoder] = 0;
		SensorValue[leftEncoder] = 0;
}
void backward(int value){
	while(SensorValue[rightEncoder] > -value){
		motor[rightBack] = -127;
		motor[rightFront] = -127;
		motor[leftBack] = -127;
		motor[leftFront] = -127;
	}
		motor[rightBack] = 0;
		motor[rightFront] = 0;
		motor[leftBack] = 0;
		motor[leftFront] = 0;
		SensorValue[rightEncoder] = 0;
		SensorValue[leftEncoder] = 0;
}
void left(int value){
	while(SensorValue[rightEncoder] < value){
		motor[rightBack] = 100;
		motor[rightFront] = 100;
	}
		motor[rightBack] = 0;
		motor[rightFront] = 0;
		SensorValue[rightEncoder] = 0;
		SensorValue[leftEncoder] = 0;
}
void leftOnSpot(int value){
	while(SensorValue[rightEncoder] < value){
		motor[rightBack] = 100;
		motor[rightFront] = 100;
		motor[leftBack] = -100;
		motor[leftFront] = -100;
	}
		motor[rightBack] = 0;
		motor[rightFront] = 0;
		motor[leftBack] = 0;
		motor[leftFront] = 0;
		SensorValue[rightEncoder] = 0;
		SensorValue[leftEncoder] = 0;
}
void leftBackward(int value){
	while(SensorValue[leftEncoder] > -value){
		motor[leftBack] = -100;
		motor[leftFront] = -100;
	}
		motor[leftBack] = 0;
		motor[leftFront] = 0;
		SensorValue[rightEncoder] = 0;
		SensorValue[leftEncoder] = 0;
}
void rightOnSpot(int value){
	while(SensorValue[leftEncoder] < value){
		motor[rightBack] = -100;
		motor[rightFront] = -100;
		motor[leftBack] = 100;
		motor[leftFront] = 100;
	}
		motor[rightBack] = 0;
		motor[rightFront] = 0;
		motor[leftBack] = 0;
		motor[leftFront] = 0;
		SensorValue[rightEncoder] = 0;
		SensorValue[leftEncoder] = 0;
}
void right(int value){
	while(SensorValue[leftEncoder] < value){
		motor[leftBack] = 100;
		motor[leftFront] = 100;
	}
		motor[leftBack] = 0;
		motor[leftFront] = 0;
		SensorValue[rightEncoder] = 0;
		SensorValue[leftEncoder] = 0;
}
void rightBackward(int value){
	while(SensorValue[rightEncoder] > -value){
		motor[rightBack] = -100;
		motor[rightFront] = -100;
	}
		motor[rightBack] = 0;
		motor[rightFront] = 0;
		SensorValue[rightEncoder] = 0;
		SensorValue[leftEncoder] = 0;
}

void intakeForward(int value){
	while(SensorValue[intakeEncoder] < value){
		motor[intake1] = 127;
		motor[intake2] = 127;
	}
		motor[intake1] = 0;
		motor[intake2] = 0;
		SensorValue[intakeEncoder]=0;
}

void intakeBack(int value){
	while(SensorValue[intakeEncoder] > -value){
		motor[intake1] = -127;
		motor[intake2] = -127;
	}
		motor[intake1] = 0;
		motor[intake2] = 0;
		SensorValue[intakeEncoder]=0;
}

void armUp(int value){
	while(SensorValue[armEncoder] < value){

		motor[armRight1] = 127;
		motor[armRight2] = 127;
		motor[armLeft1] = 127;
		motor[armLeft2] = 127;
	}
		motor[armRight1] = 0;
		motor[armRight2] = 0;
		motor[armLeft1] = 0;
		motor[armLeft2] = 0;
		SensorValue[rightEncoder] = 0;
		SensorValue[leftEncoder] = 0;
}

void armDown(int value){
	while(SensorValue[armEncoder] > value){

		motor[armRight1] = -67;
		motor[armRight2] = -67;
		motor[armLeft1] = -67;
		motor[armLeft2] = -67;
	}
		motor[armRight1] = 0;
		motor[armRight2] = 0;
		motor[armLeft1] = 0;
		motor[armLeft2] = 0;
		//reset arm sensor
}

void bluePegIntake(){
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	SensorValue[armEncoder] = 0;
	SensorValue[intakeEncoder] = 0;
	rightBackward(200);//rotate to face peg
	backward(75);//move back a little
	intakeForward(735);//move intake to bottom front
	armUp(125);
	wait1Msec(250);
	forwardSpeed(100, 80);//move forward a little more than back
	wait1Msec(250);
	intakeBack(420);//move intake with peg up
	backward(75);//backup
	rightBackward(500);//rotate to face goal
	armDown(0);//move arm down
	forwardSpeed(145,60);//move forward to goal
	wait1Msec(500);
	intakeForward(500);//score
	//intakeBack(500);//ups
	backward(75);
	/*armUp(150);//lift Arm
	right(125);//rotate to face peg
	wait1Msec(500);
	forward(300);//move forward
	wait1Msec(500);
	intakeBack(100);//move intake up
	intakeBack(400);//move intake with peg up
	backward(5);//move back a little
	leftBackward(550);//rotate to face goal
	forward(240);//move forward to goal
	wait1Msec(250);
	intakeForward(150);//score*/
	backward(150);
}

void redPegIntake(){
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	SensorValue[armEncoder] = 0;
	SensorValue[intakeEncoder] = 0;
	leftBackward(250);//rotate to face peg
	intakeForward(735);//move intake to bottom front
	armUp(125);
	wait1Msec(250);
	forwardSpeed(175, 80);//move forward a little more than back
	wait1Msec(250);
	intakeBack(420);//move intake with peg up
	backward(5);
	armDown(60);
	leftOnSpot(100);
	wait1Msec(500);
	forwardSpeed(5, 50);
	intakeForward(500);
}

void blueCubeIntake(){

}

void redCubeIntake(){
	SensorValue[rightEncoder] = 0;
	SensorValue[leftEncoder] = 0;
	SensorValue[armEncoder] = 0;
	SensorValue[intakeEncoder] = 0;
	armUp(5);//move arm up a little so intake can slide out
	intakeBack(200);//move intake right underneath
	forward(150);//move forward to cube
	wait1Msec(250);
	intakeBack(200);//move cube up
	armUp(65);//move arm up a little so intake can slide out
	intakeBack(500);//move cube up so second intake slides out
	forward(675);//move forward beside cube2
	wait1Msec(100);
	leftOnSpot(390);//turn to cube
	armDown(50);//move arm up a little so intake can slide out
	wait1Msec(100);
	forwardSpeed(500, 80);//forward to cube*/
	wait1Msec(100);
	intakeBack(85);//pick up second cube
	/*rightBackward(100);//turn right towards medium post
	wait1Msec(100);
	backward(125);
	/*wait1Msec(100);
	armUp(875);//lift arm on top of post       TODO
	wait1Msec(500);
	forwardSpeed(260, 50);//move over post
	wait1Msec(100);
	armDown(810);
	intakeForward(1000);//drop both cubes into post
	//armDown(0);//drop arm down
	/*leftOnSpot(375);//move away from post
	right(700);//turn around
	forward(75);//move to cube
	intakeBack(50);//pick up third cube
	right(350);//turn to face goal
	forward(400);//forward near, but not on goal
	armUp(1500);//lift arm on top of post       TODO*/
}

int total_distance (float inches) {
	float rotations = inches/12.57;
	int count = rotations*135;
	return count;
}

void counterPylon(){
	forward(total_distance(36));
	leftOnSpot(175);
	forward(total_distance(146));
	wait1Msec(500);
	right(650);
	wait1Msec(500);
	forward(total_distance(258));
	right(50);
	forward(total_distance(126));
	backward(250);
}

int whichCode = 0;
string programNames[5] = {"redPeg", "bluePeg", "redCube", "blueCube", "counterPylon"};

void pre_auton(){
	//be honest, you dont know what this does, dont touch it, keep it true
	bStopTasksBetweenModes = true;

	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;
	clearLCDLine(0);
	clearLCDLine(1);
	displayLCDCenteredString(0, "dfsdfsdfsd");
	displayLCDCenteredString(1, "<    Enter!    >");
	while(nLCDButtons != 2){
		displayLCDCenteredString(0, programNames[whichCode]);
		displayLCDCenteredString(1, "<    Enter!    >");
		while(nLCDButtons == 0){
			wait1Msec(5);
		}
		if(nLCDButtons == 1){
			while(nLCDButtons != 0){
				wait1Msec(10);
			}
			whichCode--;
			if(whichCode < 0){
				whichCode = 4;
			}
			}else if(nLCDButtons == 4){
			while(nLCDButtons != 0){
				wait1Msec(10);
			}
			whichCode++;
			if(whichCode >= 5){
				whichCode = 0;
			}
		}
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
	switch(whichCode){
		case 0:
			redPegIntake();
			break;
		case 1:
			bluePegIntake();
			break;
		case 2:
			redCubeIntake();
			break;
		case 3:
			blueCubeIntake();
			break;
		case 4:
			counterPylon();
			break;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	int lift = 0;
	int encoderValue = 0;
	SensorValue[leftEncoder] = 0;
	SensorValue[rightEncoder] = 0;

	while(true){
		motor[rightFront] = vexRT[Ch2];
		motor[rightBack] = vexRT[Ch2];
		motor[leftFront] = vexRT[Ch3];
		motor[leftBack] = vexRT[Ch3];

		//Arm Control
		if(vexRT[Btn6UXmtr2]){
			motor[armLeft1] = 127;
			motor[armLeft2] = 127;
			motor[armRight1] = 127;
			motor[armRight2] = 127;
		}else if(vexRT[Btn6DXmtr2]){
			motor[armLeft1] = -127;
			motor[armLeft2] = -127;
			motor[armRight1] = -127;
			motor[armRight2] = -127;
		}else{
			motor[armLeft1] = 0;
			motor[armLeft2] = 0;
			motor[armRight1] = 0;
			motor[armRight2] = 0;
		}
		if(vexRT[Btn5UXmtr2]){
			motor[intake1] = -127;
			motor[intake2] = -127;
		}else if(vexRT[Btn5DXmtr2]){
			motor[intake1] = 127;
			motor[intake2] = 127;
		}else{
			motor[intake1] = 0;
			motor[intake2] = 0;
		}
	}
}