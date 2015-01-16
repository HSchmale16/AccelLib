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
acc::Accel::Accel(int pin)
	:m_id(NEXT_ACCEL_ID), m_pin(pin)
{
    NEXT_ACCEL_ID++;
}

// ================  Function Imple    =======================================

