

void handleMovement(int moveX, int moveY, int motorMax){

	if(moveX == 0 && moveY == 0){
		motor[motorB] = 0;
		motor[motorC] = 0;
		}else if(moveX == 0 && moveY == 1){

		motor[motorB] = motorMax;
		motor[motorC] = motorMax;

		}else if(moveX == 1 && moveY == 1){

		motor[motorB] = motorMax;
		motor[motorC] = motorMax/3;

		}else if(moveX == 1 && moveY == 0){

		motor[motorB] = motorMax;
		motor[motorC] = -motorMax;

		}else if(moveX == 1 && moveY == -1){

		motor[motorB] = -motorMax;
		motor[motorC] = -motorMax/3;

		}else if(moveX == 0 && moveY == -1){

		motor[motorB] = -motorMax;
		motor[motorC] = -motorMax;

		}else if(moveX == -1 && moveY == -1){

		motor[motorB] = -motorMax/3;
		motor[motorC] = -motorMax;

		}else if(moveX == -1 && moveY == 0){

		motor[motorB] = -motorMax;
		motor[motorC] = motorMax;

		}else if(moveX == -1 && moveY == 1){

		motor[motorB] = motorMax/3;
		motor[motorC] = motorMax;

	}

}


void moveByLight(int lightLvl, int motorMax){

	int moveX = 0;
	int moveY = 0;

	if(lightLvl < 550){

		//moveX ++;;
		//moveY --;
		moveX ++;;
		moveY ++;

		}else{

		moveX --;
		moveY ++;

	}

	handleMovement(moveX, moveY, motorMax);

}

void handleRcButton(int buttonId, int motorMaxNormal) {
	if(buttonId == 0) { // nothin
		handleMovement(0, 0, 0);
	} else if(buttonId == 1) { // red up
		handleMovement(0, 1, motorMaxNormal);
	} else if(buttonId == 2) { // red down
		handleMovement(0, -1, motorMaxNormal);
	} else if(buttonId == 3) { // blue up
		handleMovement(1, 0, motorMaxNormal);
	} else	if(buttonId == 4) { // blue down
		handleMovement(-1, 0, motorMaxNormal);

	} else if(buttonId == 5) { //Red Up and Blue Up
		handleMovement(1, 1, motorMaxNormal);
	} else if(buttonId == 6) { //	Red Up and Blue Down
		handleMovement(-1, 1, motorMaxNormal);
	} else if(buttonId == 7) { //Red Down and Blue Up
		handleMovement(1, -1, motorMaxNormal);
	} else if(buttonId == 8) { //Red Down and Blue Down
		handleMovement(-1, -1, motorMaxNormal);

	}else {
		handleMovement(0, 0, 0);
	}
	displayBigTextLine(5, "%d", buttonId);
}


task main()
{

	int motorMaxNormal = 100;
	int motorMax = motorMaxNormal;

	while(true) {

		int rc_buttonId = getIRRemoteButtons(S4);

		if (rc_buttonId == 9) { // bacon
			setMotorSpeed(motorB, 100);
			setMotorSpeed(motorC, -100);
		} else if(rc_buttonId >= 0) {
			handleRcButton(rc_buttonId, motorMax);
		}

		wait1Msec(50);
	}



}
