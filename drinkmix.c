task main()
{
	int speed = 20;
	while(true) {
		motor[motorB] = -speed;
		motor[motorC] = speed;
		wait1Msec(3000);
		motor[motorB] = 0;
		motor[motorC] = 0;
		wait1Msec(1000);
		motor[motorB] = speed;
		motor[motorC] = -speed;
		wait1Msec(3000);
		motor[motorB] = 0;
		motor[motorC] = 0;
		wait1Msec(1000);
		
		speed += 20;
		if(speed > 60) {
			speed = 20;
		}
	}


}