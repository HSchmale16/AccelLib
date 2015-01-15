#ifndef GPIO_HPP_INCLUDED
#define GPIO_HPP_INCLUDED

/** @file GPIO.hpp
 * Primary Header for GPIO lib
 * This library uses the sysfs method for working with GPIO Pins.
 * @author Henry J Schmale
 * @date January 15, 2015
 */

/** \brief Functions for working with GPIO on various development boards
 */
namespace gpio
{
// ========================= TYPEDEFS  ========================================


// ========================= CONSTANTS ========================================
// PIN Constants

/** \brief GPIO_PIN enumeration
 * An enumeration containing the values of the GPIO pins.
 */
enum GPIO_PIN
{
    GPIO_3 = 3,
    GPIO_5 = 5,
    GPIO_7 = 7,
    GPIO_8 = 8,
    GPIO_10 = 10,
    GPIO_11 = 11,
    GPIO_12 = 12,
    GPIO_13 = 13,
    GPIO_15 = 14,
    GPIO_16 = 16,
    GPIO_18 = 18,
    GPIO_19 = 19,
    GPIO_21 = 21,
    GPIO_22 = 22,
    GPIO_23 = 23,
    GPIO_24 = 24,
    GPIO_26 = 26
};// Close GPIO_PIN enum

/** \brief the pinMode of a specific pin is described by this enumeration
 */
enum GPIO_MODE
{
    GPIO_INPUT, /**< Input mode */
    GPIO_OUTPUT /**< Output mode */
};

// ========================= Functions ========================================
void pinMode(GPIO_PIN pin, GPIO_MODE mode);

}

#endif // GPIO_HPP_INCLUDED
