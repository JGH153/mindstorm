
int motASpeed = 53;
int motCSpeed = 30;

void runOpenGate() {
	motor[motorC] = motCSpeed;
	wait1Msec(300);
	motor[motorC] = 0;
}

void runCloseGate() {
	motor[motorC] = -motCSpeed;
	wait1Msec(300);
	motor[motorC] = 0;
}

void runExtendArm() {
	motor[motorA] = -motASpeed;
	wait1Msec(300);
	motor[motorA] = 0;
}

void runRetractArm() {
	motor[motorA] = motASpeed;
	wait1Msec(300);
	motor[motorA] = 0;
}

task main()
{


	while(true) {
		int touch = SensorValue(S1);
		int rc_buttonId = getIRRemoteButtons(S4);
		//displayBigTextLine(5, "%d", rand());
		if (touch || rc_buttonId == 1) { //red up!
			wait1Msec(1500);
			runOpenGate();
			runExtendArm();
			runRetractArm();
			runCloseGate();
			wait1Msec(100);
		}
		wait1Msec(15);
	}




}
