#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  armEncoder,     sensorQuadEncoder)
#pragma config(Sensor, dgtl9,  intakeEncoder,  sensorQuadEncoder)
#pragma config(Sensor, dgtl11, leftEncoder,    sensorQuadEncoder)
#pragma config(Motor,  port1,           rightBack,     tmotorVex393, openLoop)
#pragma config(Motor,  port2,           rightFront,    tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port3,           armRight1,     tmotorVex393, openLoop)
#pragma config(Motor,  port4,           armRight2,     tmotorVex393, openLoop)
#pragma config(Motor,  port5,           intake1,       tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port6,           intake2,       tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port7,           armLeft2,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port8,           armLeft1,      tmotorVex393, openLoop, reversed)
#pragma config(Motor,  port9,           leftFront,     tmotorVex393, openLoop)
#pragma config(Motor,  port10,          leftBack,      tmotorVex393, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main(){
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
			motor[intake1] = 127;
			motor[intake2] = 127;
		}else if(vexRT[Btn5DXmtr2]){
			motor[intake1] = -127;
			motor[intake2] = -127;
		}else{
			motor[intake1] = 0;
			motor[intake2] = 0;
		}

	}
}
