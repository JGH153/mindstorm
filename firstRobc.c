task main()
{
	/*motor[motorA] = 30;
	motor[motorB] = 10;
	displayMotorValues();
	wait1Msec(1500);
	int touch = SensorValue(S1);
	if (touch) {
	motor[motorC] = 10;
	wait1Msec(1500);
	}
	displayBigTextLine(3, "ROBOTC");

	wait1Msec(1500);
	*/

	//resetGyro(S3);

	while(true) {
		//int touch = SensorValue(touch);
		//long gyroDeg = getGyroDegrees(S3);
		//long gyroHead = getGyroHeading(S3);
		//long gyroRate =  getGyroRate(S3);
		int rc_buttonId = getIRRemoteButtons(S4);
		//long rc_strength = getIRBeaconStrength(S4);
		//long irDistance = getIRDistance(S4);

		long redValue;
		long greenValue;
		long blueValue;
		//getColorRGB(S2, redValue, greenValue, blueValue);

		if(rc_buttonId == 0) { // nothin
			setMotorSpeed(motorA, 0);
			setMotorSpeed(motorB, 0);
			setMotorSpeed(motorC, 0);
		}

		if(rc_buttonId == 1) { // red up
			setMotorSpeed(motorB, 100);
			setMotorSpeed(motorC, 100);
		}
		if(rc_buttonId == 2) { // red down
			setMotorSpeed(motorB, -100);
			setMotorSpeed(motorC, -100);
		}
		if(rc_buttonId == 3) { // blue udown
			setMotorSpeed(motorB, 100);
			setMotorSpeed(motorC, -100);
		}
		if(rc_buttonId == 4) { // blue down
			setMotorSpeed(motorB, -100);
			setMotorSpeed(motorC, 100);
		}

		if (rc_buttonId == 9) { // bacon
			setMotorSpeed(motorA, 100);
		}

		//setMotorSpeed(motorA, 100);



		//displayBigTextLine(1, "%d", touch);
		//if(gyroDeg > 90) {
			//displayBigTextLine(3, "yess");
			//playSound(soundBeepBeep);
			//setLEDColor(ledOrange);
		//}
		//displayBigTextLine(5, "%d", redValue);
		//displayBigTextLine(7, "%d", greenValue);
		//displayBigTextLine(9, "%d", blueValue);

		//wait1Msec(1500);
	}

}
