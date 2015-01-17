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
const int X_AXIS_PIN_1 = A0;    // Pin to listen on for x-axis
const int Y_AXIS_PIN_1 = A1;    // "" y-axis
const int Z_AXIS_PIN_1 = A2;    // etc
const int X_AXIS_PIN_2 = A3;
const int Y_AXIS_PIN_2 = A4;
const int Z_AXIS_PIN_2 = A5;

// globals
acc::Accel accX1 = acc::initAccel(X_AXIS_PIN_1); // init by value
acc::Accel accY1 = acc::initAccel(Y_AXIS_PIN_1);
acc::Accel accZ1; // this one used to demo other init method
acc::Accel3d acc3d; // there are also 2 ways to init this

// init
void setup()
{
	Serial.begin(9600);
	Serial.println("Hello World!");
	acc::initAccel(&accZ1, Z_AXIS_PIN_1); // other accel init method
	acc::initAccel3d(&acc3d, X_AXIS_PIN_2, Y_AXIS_PIN_2,
			Z_AXIS_PIN_2);
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
	Serial.print("\tdX1 = "); // X Axis
	Serial.print(accX1.m_currRot - accX1.m_prevRot);
	Serial.print("\tdY1 = "); // Y Axis
	Serial.print(accY1.m_currRot - accY1.m_prevRot);
	Serial.print("\tdZ1 = "); // Z Axis
	Serial.println(accZ1.m_currRot - accZ1.m_prevRot);
	Serial.print("\tdX2 = ");

	// sleep
	delay(UPDATE_DELAY);
}
