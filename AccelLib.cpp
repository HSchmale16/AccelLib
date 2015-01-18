/** Primary Implementation of AccelLib
 * @author Henry J Schmale
 * @date January 15, 2015
 */

#include "AccelLib.h"

#ifdef ARDUINO // Arduino only stuff
#include "Arduino.h"
#endif // ARDUINO

// ================    File Globals    =======================================
static int NEXT_ACCEL_ID = 0; /**< next accelerometer id */

// ================ Structs Ctor Imple =======================================


// ================  Function Imple    =======================================
// ----------------  Cross-Platform    ---------------------------------------

// init an accel instance return by value
acc::Accel acc::initAccel(int pin)
{
	Accel myAccel;
	myAccel.m_pin = pin;
	myAccel.m_id = NEXT_ACCEL_ID++;
	updateAccel(&myAccel); // get first read data
	myAccel.m_initRot = myAccel.m_currRot;
	return myAccel;
}

void acc::initAccel(Accel *a, int pin)
{
	a->m_id = NEXT_ACCEL_ID++;
	a->m_pin = pin;
	updateAccel(a); // get first read data

}

void acc::updateAccel(Accel *a)
{
#ifdef ARDUINO
	a->m_prevRot = a->m_currRot;
	a->m_currRot = analogRead(a->m_pin);
#else
	// read the analog values some other way this will probably be dependent on
	// the platform
#endif // ARDUINO
}


acc::Accel3d acc::initAccel3d(int xpin, int ypin, int zpin)
{
    Accel3d a3d;
    initAccel(&a3d.xAxis, xpin);
    initAccel(&a3d.yAxis, ypin);
    initAccel(&a3d.zAxis, zpin);
    return a3d;
}

void acc::initAccel3d(Accel3d *a3d, int xpin, int ypin, int zpin)
{
    initAccel(&a3d->xAxis, xpin);
    initAccel(&a3d->yAxis, ypin);
    initAccel(&a3d->zAxis, zpin);
}

void acc::updateAccel3d(Accel3d* a3d)
{
    updateAccel(&a3d->xAxis);
    updateAccel(&a3d->yAxis);
    updateAccel(&a3d->zAxis);
}

// ----------------  Not available on arduino --------------------------------
#ifndef ARDUINO

#endif // ! Defined ARDUINO
