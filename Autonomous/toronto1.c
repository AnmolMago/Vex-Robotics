#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl2,  solenoid,       sensorDigitalOut)
#pragma config(Sensor, I2C_1,  rightEncoderValue, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  leftEncoderValue, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  armLeftEncoderValue, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  armRightEncoderValue, sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           intakeLeft,    tmotorVex393, openLoop)
#pragma config(Motor,  port2,           armRight2,     tmotorVex393, openLoop, reversed, encoder, encoderPort, I2C_4, 1000)
#pragma config(Motor,  port3,           armRight1,     tmotorVex393, openLoop)
#pragma config(Motor,  port4,           rightFront,    tmotorVex393, openLoop, encoder, encoderPort, I2C_1, 1000)
#pragma config(Motor,  port5,           rightBack,     tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           leftBack,      tmotorVex393, openLoop)
#pragma config(Motor,  port7,           leftFront,     tmotorVex393HighSpeed, openLoop)
#pragma config(Motor,  port8,           armLeft1,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           armLeft2,      tmotorVex393, openLoop, encoder, encoderPort, I2C_3, 1000)
#pragma config(Motor,  port10,          intakeRight,   tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

int leftEncoder =0, rightEncoder=0, armLeftEncoder=0, armRightEncoder=0;

void pickPeg(){
	SensorValue[solenoid] = 0;
	wait1Msec(1000);
	SensorValue[solenoid] = 1;
}

void updateEncoders(){
		leftEncoder = nMotorEncoder[leftFront];
		rightEncoder = nMotorEncoder[rightFront]*-1;
		armLeftEncoder = nMotorEncoder[armLeft2]*-1;
		if(armLeftEncoder < 0){
			nMotorEncoder[armLeft2] = 0;
			armLeftEncoder = 0;
		}
		armRightEncoder = nMotorEncoder[armRight2]*-1;
		if(armRightEncoder < 0){
			nMotorEncoder[armLeft2] = 0;
			armRightEncoder = 0;
		}
}

void turnToPeg(){
	updateEncoders();
	while(leftEncoder > 0 || armLeftEncoder < 0){
		if(leftEncoder < 500){
			motor[leftBack] = -127;
			motor[leftFront] = -127;
			motor[rightBack] = 127;
			motor[rightFront] = 127;
		}else{
			motor[leftBack] = 0;
			motor[leftFront] = 0;
			motor[rightBack] = 0;
			motor[rightFront] = 0;
		}
		if(armLeftEncoder < 0){
			motor[armLeft1] = 127;
			motor[armLeft2] = 127;
			motor[armRight1] = 127;
			motor[armRight2] = 127;
		}else{
			motor[armLeft1] = 0;
			motor[armLeft2] = 0;
			motor[armRight1] = 0;
			motor[armRight2] = 0;
		}
		updateEncoders();
	}
}

void turnToGoal(int pegNum){
	int startHeight = 75;//initial drop height
	int pegDifference = 175;//each peg is same size, so the amount that it must go up should be same too
	int height = startHeight + (pegDifference * pegNum);//calculate height to score peg from
	updateEncoders();
	while(leftEncoder < 500 || armLeftEncoder < height){
		if(leftEncoder < 500){
			motor[leftBack] = 127;
			motor[leftFront] = 127;
			motor[rightBack] = -127;
			motor[rightFront] = -127;
		}else{
			motor[leftBack] = 0;
			motor[leftFront] = 0;
			motor[rightBack] = 0;
			motor[rightFront] = 0;
		}
		if(armLeftEncoder < height){
			motor[armLeft1] = 127;
			motor[armLeft2] = 127;
			motor[armRight1] = 127;
			motor[armRight2] = 127;
		}else{
			motor[armLeft1] = 0;
			motor[armLeft2] = 0;
			motor[armRight1] = 0;
			motor[armRight2] = 0;
		}
		updateEncoders();
	}
}

void dropToPeg(){
	while(armLeftEncoder > 0){
		motor[armLeft1] = 127;
		motor[armLeft2] = 127;
		motor[armRight1] = 127;
		motor[armRight2] = 127;
		updateEncoders();
	}
		motor[armLeft1] = 0;
		motor[armLeft2] = 0;
		motor[armRight1] = 0;
		motor[armRight2] = 0;
}

void score(){
	int end = armLeftEncoder - 200;
	updateEncoders();
	while(armLeftEncoder > end){
		motor[armLeft1] = -127;
		motor[armLeft2] = -127;
		motor[armRight1] = -127;
		motor[armRight2] = -127;
		updateEncoders();
	}
		motor[armLeft1] = 0;
		motor[armLeft2] = 0;
		motor[armRight1] = 0;
		motor[armRight2] = 0;
		nMotorEncoder[leftFront] = 0;
}

task main(){
	nMotorEncoder[leftFront] = 0;
	nMotorEncoder[rightFront] = 0;
	nMotorEncoder[armLeft2] = 0;
	nMotorEncoder[armRight2] = 0;
	wait1Msec(1000);
	//flip peg prolly like armUp(100)
	SensorValue[solenoid] = 1;
	//pickPeg(); do not use, first one only closes to save time
}
