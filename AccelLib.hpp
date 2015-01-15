#ifndef ACCELLIB_HPP_INCLUDED
#define ACCELLIB_HPP_INCLUDED

/** @file AccelLib.hpp
 * Primary Header for AccelLib
 * @author Henry J Schmale
 * @date January 15, 2015
 */

#include "GPIO.hpp"

/// Functions to work with accelerometers live here!!
namespace acc
{

// ========================= Structs ==========================================

/** \brief describes an accelerometer's rotation in 3 dimensional space.
 */
struct Rotate3d
{
    int m_xRot;
    int m_yRot;
    int m_zRot;
};

/** \brief Struct to hold values of a 3d accelerometer
 * This struct is holds the data to work with accelerometers
 */
struct Accel3d
{
	const int m_id;   /**< Id of that accelerometer */
	// Rotation
	int m_xRot; /**< Rotation on x-axis */
	int m_yRot; /**< Rotation on y-axis */
	int m_zRot; /**< Rotation on z-axis */
	// Pins
	gpio::GPIO_PIN_t m_xPin; /**< Pin to read x-axis from */
	gpio::GPIO_PIN_t m_yPin; /**< Pin to read y-axis from */
	gpio::GPIO_PIN_t m_zPin; /**< Pin to read z-axis from */

	// ctor
	Accel3d(gpio::GPIO_PIN_t x, gpio::GPIO_PIN_t y,
			gpio::GPIO_PIN_t z, int id);
};

// ========================= Functions =======================================

/** \brief Initializes an internal accelerometer which can be accessed by
    readAccel().
 *
 * \param x_pin - GPIO Pin to read to get x - axis value
 * \param y_pin - Same, y axis
 * \param z_pin - Same, z axis
 * \return Returns the id of the initialized accelerometer, starting from 0
 * Adds a new instance
 */
int initAccel3d(gpio::GPIO_PIN_t x_pin, gpio::GPIO_PIN_t y_pin,
				gpio::GPIO_PIN_t z_pin);

/** \brief Get the rotation of an accelerometer instance by value.
 * \param id - the id of the accelerometer to get the rotation of
 */
Rotate3d getRotation3d(int id);

}// end namespace acc

#endif // ACCELLIB_HPP_INCLUDED
