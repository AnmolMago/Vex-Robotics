#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  frontRightEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  backRightEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  backLeftEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  frontLeftEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  pegSolenoid,    sensorDigitalOut)
#pragma config(Sensor, dgtl10, cubeSolenoid,   sensorDigitalOut)
#pragma config(Sensor, I2C_1,  armRight,       sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  armLeft,        sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           rightArm1,     tmotorVex393, openLoop)
#pragma config(Motor,  port2,           leftArm3,      tmotorVex393, openLoop, encoder, encoderPort, I2C_2, 1000)
#pragma config(Motor,  port3,           leftArm2,      tmotorVex393, openLoop)
#pragma config(Motor,  port4,           frontRight,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393, openLoop)
#pragma config(Motor,  port6,           backRight,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           frontLeft,     tmotorVex393, openLoop)
#pragma config(Motor,  port8,           rightArm2,     tmotorVex393, openLoop, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port9,           rightArm3,     tmotorVex393, openLoop)
#pragma config(Motor,  port10,          leftArm1,      tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//4 6   peg goal
//7 5   peg intake
//made by:anmol
//356B bot
int encoderAverage = 0;

void updateAverage(){
	//encoderAverage = (SensorValue[frontLeftEncoder] + SensorValue[frontRightEncoder] + SensorValue[backRightEncoder] + SensorValue[backLeftEncoder])/4;
	encoderAverage = (SensorValue[frontLeftEncoder] + SensorValue[frontRightEncoder] + SensorValue[backLeftEncoder])/3;
	//encoderAverage = SensorValue[backLeftEncoder];
}

void resetEncoders(){
	SensorValue[frontLeftEncoder] = 0;
	SensorValue[frontRightEncoder] = 0;
	SensorValue[backRightEncoder] = 0;
	SensorValue[backLeftEncoder] = 0;
	encoderAverage = 0;
}

void turnLeft(int value){
	resetEncoders();
	while(encoderAverage < value){
		motor[frontRight] = 127;
		motor[frontLeft] = -127;
		motor[backRight] = 127;
		motor[backLeft] = -127;
		updateAverage();
	}
	motor[frontRight] = 0;
	motor[frontLeft] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	resetEncoders();
}

void turnRight(int value){
	resetEncoders();
	while(encoderAverage > -value){
		motor[frontRight] = -127;
		motor[frontLeft] = 127;
		motor[backRight] = -127;
		motor[backLeft] = 127;
		updateAverage();
	}
	motor[frontRight] = 0;
	motor[frontLeft] = 0;
	motor[backRight] = 0;
	motor[backLeft] = 0;
	resetEncoders();
}

void armUp(){
	motor[leftArm1] = 127;
	motor[leftArm2] = 127;
	motor[leftArm3] = 127;
	motor[rightArm1] = 127;
	motor[rightArm2] = 127;
	motor[rightArm3] = 127;
}

void armUp(int value){
	int speed = 120;
	while(SensorValue[armLeft] < value){
		motor[leftArm1] = speed;
		motor[leftArm2] = speed;
		motor[leftArm3] = speed;
		motor[rightArm1] = speed;
		motor[rightArm2] = speed;
		motor[rightArm3] = speed;
	}
		speed = 0;
		motor[leftArm1] = 0;
		motor[leftArm2] = 0;
		motor[leftArm3] = 0;
		motor[rightArm1] = 0;
		motor[rightArm2] = 0;
		motor[rightArm3] = 0;
}

void armDown(){
	motor[leftArm1] = -127;
	motor[leftArm2] = -127;
	motor[leftArm3] = -127;
	motor[rightArm1] = -127;
	motor[rightArm2] = -127;
	motor[rightArm3] = -127;
}

void armDown(int value){
	int speed = -60;
	while(SensorValue[armLeft] > value){
		motor[leftArm1] = speed;
		motor[leftArm2] = speed;
		motor[leftArm3] = speed;
		motor[rightArm1] = speed;
		motor[rightArm2] = speed;
		motor[rightArm3] = speed;
	}
		speed = 0;
		motor[leftArm1] = 0;
		motor[leftArm2] = 0;
		motor[leftArm3] = 0;
		motor[rightArm1] = 0;
		motor[rightArm2] = 0;
		motor[rightArm3] = 0;
}

void armStop(){
	motor[leftArm1] = 0;
	motor[leftArm2] = 0;
	motor[leftArm3] = 0;
	motor[rightArm1] = 0;
	motor[rightArm2] = 0;
	motor[rightArm3] = 0;
}

void pegClose(){
	SensorValue[pegSolenoid] = 0;
}

void pegCloseUp(int value){
	wait1Msec(1000);
	SensorValue[pegSolenoid] = 0;
	armUp(value);
}

void pegOpen(){
	SensorValue[pegSolenoid] = 1;
}

void helper(int count){
	int delay = 750;
	//
	pegClose();
	armUp(200 + (125*count));
	turnRight(460);
	wait1Msec(delay/2);
	armDown(0 + (125*count));
	pegOpen();
	wait1Msec(delay/2);
	armDown(0);
	turnLeft(410);
	wait1Msec(delay/2);
	/*if(count < 2){
		armDown(0);
		turnLeft(440);
		wait1Msec(delay/2);
		pegClose();
	}else{
		turnLeft(1100);
		armUp(600);
	}*/
}

task main(){
	armUp(150);
	armDown(0);
	pegOpen();
	turnLeft(40);
	wait1Msec(750);
	helper(0);
	helper(1);
	helper(2);
	helper(3);
}
void driver(){
	while(true){
		motor[frontRight] = vexRT[Ch2] - vexRT[Ch1];
    motor[backRight] =  vexRT[Ch2] + vexRT[Ch1];
    motor[backLeft] = vexRT[Ch3] - vexRT[Ch4];
    motor[frontLeft] =  vexRT[Ch3] + vexRT[Ch4];
    if(vexRT[Btn6UXmtr2]){
    	armUp();
    }else if(vexRT[Btn6DXmtr2]){
    	armDown();
  	}else{
  		armStop();
  	}
  	if(vexRT[Btn7R]){
			motor[frontRight] = -127;
			motor[frontLeft] = 127;
			motor[backRight] = -127;
			motor[backLeft] = 127;
  	}else if(vexRT[Btn7L]){
			motor[frontRight] = 127;
			motor[frontLeft] = -127;
			motor[backRight] = 127;
			motor[backLeft] = -127;
  	}
  	if(vexRT[Btn8DXmtr2] == 1){
  		SensorValue[cubeSolenoid] = 0;
  	}else{
  		SensorValue[cubeSolenoid] = 1;
  	}
  	if(vexRT[Btn8RXmtr2] == 1){
  		SensorValue[pegSolenoid] = 1;
  	}else{
  		SensorValue[pegSolenoid] = 0;
  	}
	}
}
