/** Demos Basic Usage My Accelerometer Library
 * Prints out the change on each axis every 500ms.
 * Circuit: Arduino and ADXL 3xx Accelerometer
 *  Accel inputs on arduino analog ins
 * @author Henry J Schmale
 * @date January 16, 2015
 */

#include <AccelLib.h>

// constants 
const int UPDATE_DELAY = 500; // ms to wait between updates
const int X_AXIS_PIN = A0;
const int Y_AXIS_PIN = A1;
const int Z_AXIS_PIN = A2;

// globals
acc::Accel accX1 = acc::initAccel(A0); // init by value
acc::Accel accY1 = acc::initAccel(A1);
acc::Accel accZ1; // this one used to demo other init method

// init
void setup()
{
	Serial.begin(9600);
	Serial.println("Hello World!");
	acc::initAccel(&accZ1, Z_AXIS_PIN); // other accel init method
}

// Event loop
void loop()
{
	// update accel with newest data
	acc::updateAccel(&accX1);
	acc::updateAccel(&accY1);
	acc::updateAccel(&accZ1);

	// print data
	Serial.print("Time Index: ");
	Serial.println(millis());
	Serial.print("dX = "); // X Axis
	Serial.println(accX1.m_currRot - accX1.m_prevRot);
	Serial.print("dY = "); // Y Axis
	Serial.println(accY1.m_currRot - accY1.m_prevRot);
	Serial.print("dZ = "); // Z Axis
	Serial.println(accZ1.m_currRot - accZ1.m_prevRot);
	delay(UPDATE_DELAY);
}
