/** GPIO Implementation
 * @author Henry J Schmale
 * @date January 15, 2015
 */

#include "rPiGPIO.hpp"
#include <fstream>
#include <vector>
#include <sstream>

// ================== File Scope Constants ====================================

// File path to export a pin
const std::string EXPORT_PATH = "/sys/class/gpio/export";

// File path to unexport a pin
const std::string UNEXPORT_PATH = "/sys/class/gpio/unexport";

// Path to read a pin

// ================== File Scope Variables ====================================
std::vector<gpio::GPIO_PIN_t> ExportedPins;

// ================== IMPLEMENTATION ==========================================


// ================== Namespace Member Functions ==============================
// export a pin
void gpio::activatePin(GPIO_PIN_t pin)
{
	for(unsigned int i = 0; i < ExportedPins.size(); i++)
	{
		if(ExportedPins[i].compare(pin) == 0) // is it already exported?
		{
			return;
		}
	}
	std::ofstream eGPIO(EXPORT_PATH.c_str());
	if(eGPIO < 0)
	{
		return;    // Fail to open
	}
	eGPIO << pin;
	eGPIO.close();
	ExportedPins.push_back(pin);
	return;
}

// unexport a specific pin
void gpio::deactivatePin(GPIO_PIN_t pin)
{
	std::ofstream eGPIO(UNEXPORT_PATH.c_str());
	if(eGPIO < 0)
	{
		return;
	}
	// check if pin was already exported
	for(unsigned int i = 0; i < ExportedPins.size(); i++)
	{
		if(ExportedPins[i].compare(pin) == 0)
		{
			ExportedPins.erase(ExportedPins.begin() + i);
			eGPIO << pin;
			break;
		}
	}
	eGPIO.close();
}

// unexport all the pins
void gpio::clean()
{
	std::ofstream eGPIO(UNEXPORT_PATH.c_str());
	if(eGPIO < 0)
	{
		return;
	}
	// check if pin was already exported
	for(unsigned int i = 0; i < ExportedPins.size(); i++)
	{
		eGPIO << ExportedPins[i];
		ExportedPins.erase(ExportedPins.begin() + i);
	}
	eGPIO.close();
}

// set the pin mode
void gpio::pinMode(GPIO_PIN_t pin, GPIO_PIN_MODE_t mode)
{

}

// Set a pin to HIGH or LOW
void gpio::digitalWrite(GPIO_PIN_t pin, GPIO_PIN_STATE_t state)
{

}

// Read Pin State
gpio::GPIO_PIN_STATE_t gpio::digitalRead(GPIO_PIN_t pin)
{
	return LOW;
}

// Write out an analog value, this will launch a
void gpio::analogWrite(GPIO_PIN_t pin, int value)
{

}

// read an analog value from a pin
int gpio::analogRead(GPIO_PIN_t pin)
{
    return 0;
}
