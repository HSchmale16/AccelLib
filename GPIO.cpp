/** GPIO Implementation
 * @author Henry J Schmale
 * @date January 15, 2015
 */

#include "GPIO.hpp"
#include <fstream>
#include <vector>

// ================== File Scope Constants ====================================

// File path to export a pin
const std::string EXPORT_PATH = "/sys/class/gpio/export";

// File path to unexport a pin
const std::string UNEXPORT_PATH = "/sys/class/gpio/unexport";

// Path to read a pin

// ================== File Scope Variables ====================================
std::vector<gpio::GPIO_PIN_t> ExportedPins;

// ================== IMPLEMENTATION ==========================================
void gpio::activatePin(gpio::GPIO_PIN_t pin)
{
	for(unsigned int i = 0; i < ExportedPins.size(); i++)
	{
        if(ExportedPins[i].compare(pin) == 0)
			return;
	}
	std::ofstream eGPIO(EXPORT_PATH.c_str());
	if(eGPIO < 0)
		return; // Fail to open
	eGPIO << pin;
	eGPIO.close();
	ExportedPins.push_back(pin);
	return;
}

void gpio::deactivatePin(gpio::GPIO_PIN_t pin)
{
	std::ofstream eGPIO(UNEXPORT_PATH.c_str());
	if(eGPIO < 0)
		return;
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

void gpio::clean()
{

}
