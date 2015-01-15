#ifndef GPIO_HPP_INCLUDED
#define GPIO_HPP_INCLUDED

/** @file GPIO.hpp
 * Primary Header for GPIO lib
 * This library uses the sysfs method for working with GPIO Pins.
 * @author Henry J Schmale
 * @date January 15, 2015
 */

#include <string>

/** \brief Functions for working with GPIO on various development boards
 */
namespace gpio
{
// ========================= TYPEDEFS  ========================================
typedef const std::string GPIO_PIN_t; /**< A GPIO Pin */
typedef bool GPIO_PIN_STATE_t; /**< GPIO Pin State. Is it high or low?*/

// ========================= CONSTANTS ========================================
/** \brief the pinMode of a specific pin is described by this enumeration
 */
enum GPIO_PIN_MODE_t
{
	GPIO_INPUT, /**< Input mode */
	GPIO_OUTPUT /**< Output mode */
};

// ========================= Functions ========================================
/** \brief activates a pin
 * \param pin - the pin to export
 * exports a pin through sysfs. Note: if a pin is exported through this it must
	unexported as well.
 */
void activatePin(GPIO_PIN_t pin);

/** \brief deactivates a pin
 * \param pin - the pin to export
 * unexports a pin through sysfs.
 */
void deactivatePin(GPIO_PIN_t pin);

/** \brief deactivate all pins
 * Unexports all the pins
 */
void clean();

/** \brief sets a pin to be an input or output
 * \param pin - which pin to set
 * \param mode - the mode of the pin
 */
void pinMode(GPIO_PIN_t pin, GPIO_PIN_MODE_t mode);

/** \brief writes out to a pin either HIGH (on) or LOW (off)
 * \param pin - what pin to write to
 * \param state - value to write out (ON or OFF)
 */
void digitalWrite(GPIO_PIN_t pin, GPIO_PIN_STATE_t state);

/** \brief reads an input pin to be HIGH (on) or LOW (off)
 * \param pin - what pin to read
 */
GPIO_PIN_STATE_t digitalRead(GPIO_PIN_t pin);


// ================ Devboard Namespces Declarations ===========================

/** \brief GPIO Pin Constants for the Raspberry Pi
 */
namespace rPi
{
GPIO_PIN_t GPIO_3 = "3",
		   GPIO_5 = "5",
		   GPIO_7 = "7",
		   GPIO_8 = "8",
		   GPIO_10 = "10",
		   GPIO_11 = "11",
		   GPIO_12 = "12",
		   GPIO_13 = "13",
		   GPIO_15 = "14",
		   GPIO_16 = "16",
		   GPIO_18 = "18",
		   GPIO_19 = "19",
		   GPIO_21 = "21",
		   GPIO_22 = "22",
		   GPIO_23 = "23",
		   GPIO_24 = "24",
		   GPIO_26 = "26";
} // End of rPi namespace

/** \brief GPIO Pin Constants for the Beagle Bone Black
 */
namespace bbb
{

} // End of BBB namespace

} // End of GPIO namespace

#endif // GPIO_HPP_INCLUDED
