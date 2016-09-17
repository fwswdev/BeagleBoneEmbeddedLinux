//============================================================================
// Name        : HelloBeagleBone.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <stdio.h>

class Led
    {
public:

    void TurnOnLed()
	{
	FILE *fp = fopen(myStr, "w");
	fwrite("1", 1, 1, fp);
	fclose(fp);
	}

    void TurnOffLed()
	{
	FILE *fp = fopen(myStr, "w");
	fwrite("0", 1, 1, fp);
	fclose(fp);
	}

    Led(char const * valueLedPath)
	{
	this->myStr = valueLedPath;
	}

private:
    char const * myStr;

    };

int main()
    {
    int x = 0;

    Led l = Led("/sys/class/leds/beaglebone:green:usr3/brightness");
    Led l2 = Led("/sys/class/leds/beaglebone:green:usr1/brightness");
    for (int ctr = 0; ctr < 10; ctr++)
	{
	l.TurnOffLed();
	l2.TurnOffLed();
	sleep(1);
	l.TurnOnLed();
	l2.TurnOnLed();
	sleep(1);
	}

    cout << "!!!Hello fdsfds!!!" << endl; // prints !!!Hello World!!!
    return 0;
    }
