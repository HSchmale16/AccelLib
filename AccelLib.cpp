/** Primary Implementation of AccelLib
 * @author Henry J Schmale
 * @date January 15, 2015
 */

#include "AccelLib.h"

// Arduino only stuff
#ifdef ARDUINO
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
	return myAccel;
}

void acc::initAccel(Accel *a, int pin)
{
	a->m_id = NEXT_ACCEL_ID++;
	a->m_pin = pin;
}

void acc::updateAccel(Accel *a)
{
#ifdef ARDUINO
	a->m_prevRot = a->m_currRot;
	a->m_currRot = analogRead(a->m_pin);
#else
	// read the analog values some other way
#endif // ARDUINO
}

// ----------------  Not available on arduino --------------------------------
#ifndef ARDUINO

#endif // ! Defined ARDUINO
