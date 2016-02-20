#include <cstdlib>
#include <wiringPi.h>
#include <stdio.h>

void move_right(int iGpio)
{
        digitalWrite(iGpio, HIGH);
        delay(0.5);
        digitalWrite(iGpio, LOW);
		delay(25);
}

void move_left(int iGpio)
{
        digitalWrite(iGpio, HIGH);
        delay(2.5);
        digitalWrite(iGpio, LOW);      
		delay(25);
}

void move_center(int iGpio)
{
        digitalWrite(iGpio, HIGH);
        delay(1.5);
        digitalWrite(iGpio, LOW);
        delay(25);
}

int main(int argc, char** argv)
{
	if(wiringPiSetup() == -1)
	return 1;

	int iGpio = atoi(argv[1]);
	int iDirection = atoi(argv[2]);
	int iDuration = atoi(argv[3]);
	pinMode(iGpio, OUTPUT);

	while(iDuration > 0)
	{
		if(iDirection==1)
		{
			move_right(iGpio);
		}
		else if(iDirection==2)
		{
			move_left(iGpio);
		}
		else if(iDirection==3)
		{
			move_center(iGpio);
		}
		
		iDuration--;
	}
}
