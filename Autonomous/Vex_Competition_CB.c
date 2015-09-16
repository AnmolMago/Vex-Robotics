#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  claw,           sensorDigitalOut)
#pragma config(Sensor, dgtl2,  armSolenoid,    sensorDigitalOut)
#pragma config(Sensor, dgtl3,  intakeSolenoid, sensorDigitalOut)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           intakeLeft,    tmotorVex393, openLoop)
#pragma config(Motor,  port2,           armRight2,     tmotorVex393, openLoop, encoder, encoderPort, I2C_4, 1000)
#pragma config(Motor,  port3,           armRight1,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port4,           rightFront,    tmotorVex393HighSpeed, openLoop, reversed, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port5,           rightBack,     tmotorVex393HighSpeed, openLoop, reversed)
#pragma config(Motor,  port6,           leftBack,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           leftFront,     tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port8,           armLeft1,      tmotorVex393HighSpeed, openLoop, reversed)
#pragma config(Motor,  port9,           armLeft2,      tmotorVex393HighSpeed, openLoop, encoder, encoderPort, I2C_3, 1000)
#pragma config(Motor,  port10,          intakeRight,   tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

int leftEncoder =0, rightEncoder=0, armLeftEncoder=0, armRightEncoder=0;
int speed = 80, armSpeed = 80;
int open = 1, close = 0;

void updateEncoders(){
		leftEncoder = nMotorEncoder[leftFront]*-1;
		rightEncoder = nMotorEncoder[rightFront];
		armLeftEncoder = nMotorEncoder[armLeft2]*-1;
		if(armLeftEncoder < 0){
			nMotorEncoder[armLeft2] = 0;
			armLeftEncoder = 0;
		}
		armRightEncoder = nMotorEncoder[armRight2];
		if(armRightEncoder < 0){
			nMotorEncoder[armRight2] = 0;
			armRightEncoder = 0;
		}
}

void forward(int value){
	while(rightEncoder < value){
		motor[rightBack] = speed;
		motor[rightFront] = speed;
		motor[leftBack] = speed;
		motor[leftFront] = speed;
		updateEncoders();
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
	while(rightEncoder > -value){
		motor[rightBack] = -speed;
		motor[rightFront] = -speed;
		motor[leftBack] = -speed;
		motor[leftFront] = -speed;
		updateEncoders();
	}
		motor[rightBack] = 0;
		motor[rightFront] = 0;
		motor[leftBack] = 0;
		motor[leftFront] = 0;
		SensorValue[rightEncoder] = 0;
		SensorValue[leftEncoder] = 0;
}

void backRight(int value){
	updateEncoders();
	int startV = rightEncoder;
	while(rightEncoder > -value){
		motor[rightBack] = -speed;
		motor[rightFront] = -speed;
		updateEncoders();
	}
		motor[rightBack] = 0;
		motor[rightFront] = 0;
}

void backLeft(int value){
	updateEncoders();
	int startV = leftEncoder;
	while(leftEncoder > startV-value){//1
		motor[leftBack] = -speed;
		motor[leftFront] = -speed;
		updateEncoders();
	}
		motor[leftBack] = 0;
		motor[leftFront] = 0;
}

void right(int value){
	updateEncoders();
	int startV = leftEncoder;
	while(leftEncoder < startV + value){
		motor[leftBack] = speed;
		motor[leftFront] = speed;
		updateEncoders();
	}
	motor[leftBack] = 0;
	motor[leftFront] = 0;
}

void left(int value){
	updateEncoders();
	int startV = rightEncoder;
	while(rightEncoder < startV + value){
		motor[rightBack] = speed;
		motor[rightFront] = speed;
		updateEncoders();
	}
	motor[rightBack] = 0;
	motor[rightFront] = 0;
}

void armUp(int value){
	while(armLeftEncoder < value){
		motor[armLeft1] = armSpeed;
		motor[armLeft2] = armSpeed;
		motor[armRight1] = armSpeed;
		motor[armRight2] = armSpeed;
		updateEncoders();
	}
		motor[armLeft1] = 0;
		motor[armLeft2] = 0;
		motor[armRight1] = 0;
		motor[armRight2] = 0;
		updateEncoders();
}

void armDown(int value){
	while(armLeftEncoder > value){
		motor[armLeft1] = -armSpeed;
		motor[armLeft2] = -armSpeed;
		motor[armRight1] = -armSpeed;
		motor[armRight2] = -armSpeed;
		updateEncoders();
	}
		motor[armLeft1] = 0;
		motor[armLeft2] = 0;
		motor[armRight1] = 0;
		motor[armRight2] = 0;
		updateEncoders();
}

void flipOut(){
		motor[armLeft1] = 127;
		motor[armLeft2] = 127;
		motor[armRight1] = 127;
		motor[armRight2] = 127;
		wait1Msec(250);
		motor[armLeft1] = -127;
		motor[armLeft2] = -127;
		motor[armRight1] = -127;
		motor[armRight2] = -127;
		wait1Msec(250);
		SensorValue[claw] = open;
		motor[armLeft1] = 0;
		motor[armLeft2] = 0;
		motor[armRight1] = 0;
		motor[armRight2] = 0;
		nMotorEncoder[armLeft2] = 0;
		nMotorEncoder[armRight2] = 0;
}

void intake(){
	/*motor[armLeft1] = -127;
	motor[armLeft2] = -127;
	motor[armRight1] = -127;
	motor[armRight2] = -127;
	wait1Msec(200);//wait .02 sec (future: because this small thing stops bot from carrying its previous momentum forward)
	SensorValue[claw] = close;//close claw
	wait1Msec(100);
	motor[armLeft1] = 0;
	motor[armLeft2] = 0;
	motor[armRight1] = 0;
	motor[armRight2] = 0;*/
	SensorValue[claw] = close;//close claw
}

void pre_auton(){
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
  nMotorEncoder[leftFront] = 0;
  nMotorEncoder[rightFront] = 0;
  nMotorEncoder[armLeft2] = 0;
  nMotorEncoder[armRight2] = 0;
  SensorValue[claw] = 0;
  SensorValue[armSolenoid] = 0;
  SensorValue[intakeSolenoid] = 0;
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous(){
	updateEncoders();
	while(leftEncoder < 500){
		motor[leftBack] = 127;
		motor[rightBack] = 127;
		motor[leftFront] = 127;
		motor[rightFront] = 127;
		updateEncoders();
	}
	motor[leftBack] = 0;
	motor[rightBack] = 0;
	motor[leftFront] = 0;
	motor[rightFront] = 0;
}

task usercontrol(){
	bool backwardControl;
	bool slow;
	while(true){
		float ch2 = -vexRT[Ch2];
		float ch3 = -vexRT[Ch3];
		if(slow){
			ch2 *= 0.6;
			ch3 *= 0.6;
		}
		if(backwardControl){
			motor[rightFront] = ch3;
			motor[rightBack] = ch3;
			motor[leftFront] = ch2;
			motor[leftBack] = ch2;
		}else{
			motor[rightFront] = -ch3;
			motor[rightBack] = -ch3;
			motor[leftFront] = -ch2;
			motor[leftBack] = -ch2;
		}

		//Arm Control
		if(vexRT[Btn6UXmtr2]){
			if(SensorValue[armSolenoid] == 1)
				SensorValue[armSolenoid] = 0;
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
			motor[intakeLeft] = 127;
			motor[intakeRight] = 127;
		}else if(vexRT[Btn5DXmtr2]){
			motor[intakeLeft] = -127;
			motor[intakeRight] = -127;
		}else{
			motor[intakeLeft] = 0;
			motor[intakeRight] = 0;
		}
		if(vexRT[Btn7RXmtr2]){
			SensorValue[armSolenoid] = 1;
		}
		if(vexRT[Btn7DXmtr2]){
			if(SensorValue[claw] == 0){
				SensorValue[claw] = 1;
				wait1Msec(100);
			}else{
				SensorValue[claw] = 0;
				wait1Msec(100);
			}
		}
		if(vexRT[Btn6U]){
			if(backwardControl == true){
				backwardControl = false;
				wait1Msec(100);
			}else{
				backwardControl = true;
				wait1Msec(100);
			}
		}
		if(vexRT[Btn6D]){
			if(slow == true){
				slow = false;
			}else{
				slow = true;
			}
		}
    if(vexRT[Btn7LXmtr2]){
			SensorValue[intakeSolenoid] = 0;
				wait1Msec(100);
		}else{
			SensorValue[intakeSolenoid] = 1;
				wait1Msec(100);
		}
	}
}