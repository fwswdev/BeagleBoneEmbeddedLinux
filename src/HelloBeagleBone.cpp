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
#include <pthread.h>

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

void *voidthread1( void *ptr )
    {
    Led l = Led("/sys/class/leds/beaglebone:green:usr3/brightness");
    for (int ctr = 0; ctr < 5; ctr++)
	{
	l.TurnOffLed();
	sleep(2);
	l.TurnOnLed();
	sleep(2);
	}

    }

void *voidthread2( void *ptr )
    {
    Led l2 = Led("/sys/class/leds/beaglebone:green:usr1/brightness");
    for (int ctr = 0; ctr < 10; ctr++)
	{
	l2.TurnOffLed();
	sleep(1);
	l2.TurnOnLed();
	sleep(1);
	}

    }



int main()
    {
    int x = 0;

#if 0
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
#else
    pthread_t thread1, thread2;
    pthread_create( &thread1, NULL, voidthread1, NULL);
    pthread_create( &thread2, NULL, voidthread2, NULL);


    pthread_join( thread1, NULL);
    pthread_join( thread2, NULL);
#endif

    cout << "!!!Hello fdsfds!!!" << endl; // prints !!!Hello World!!!
    return 0;
    }
