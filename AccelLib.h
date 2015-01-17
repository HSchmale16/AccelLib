#ifndef ACCELLIB_H_INCLUDED
#define ACCELLIB_H_INCLUDED

/** @file AccelLib.h
 * Primary Header for AccelLib
 * @author Henry J Schmale
 * @date January 15, 2015
 */

/// Functions to work with accelerometers live here!!
namespace acc
{
// =========================  Const  ==========================================
const int ROTATION_0 = 512; /**< The 0 degrees value for ADXL 3XX accels */

// ========================= Structs ==========================================

/** \brief describes an accelerometer's values. Such as the pin to listen on
 * and it's various other params
 */
struct Accel
{
	int m_id;		/**< Id of this accelerometer */
	int m_pin;		/**< The pin that should be used for listening */
	int m_currRot;	/**< The current rotation of this accel */
	int m_prevRot;	/**< The previous rotation of this accel */
	int m_initRot;	/**< The initial rotation of this accel on start-up */
};

/** \brief an abstration of the above struct to allow for simple 3d \
accelerometers.
 */
struct Accel3d
{
    Accel xAxis;	/**< X-axis accelerometer */
    Accel yAxis;	/**< Y-axis accelerometer */
    Accel zAxis;	/**< Z-axis accelerometer */
};

// ========================= Functions =======================================
// ------------ Available on all supported platforms -------------------------

// ----- Regular Accel -----
/** \brief init an accel and return it by ptr
 * \param a - an accel struct to initialize
 * \param pin - what pin does this instances run on
 * \return Nothing
 * \note this method is more memory efficent.
 *
 */
void initAccel(Accel *a, int pin);

/** \brief initializes an accelerometer and returns it by value
 * \return An instance of the Accel struct with all of it's fields initialized
 * \note this method is very ineffient due to the costs in copying the data into
 * the requestor.
 */
Accel initAccel(int pin);

/** \brief updates an Accel instance and returns the updated version by ptr
 * \param a - the accel instance to update
 * \return an updated Accel instance by ptr
 * \note the time taken to return this function is very dependent on what
 * platform is running it, as it takes differint amounts of time to perform
 * analog read on differint platforms.
 */
void updateAccel(Accel *a);

// ------ 3d Accel ------
void initAccel3d(Accel3d *a3d, int xpin, int ypin, int zpin);

Accel3d initAccel3d(int xpin, int ypin, int zpin);

void updateAccel3d(Accel3d *a3d);

// ------------ Not Available on Arduino -------------------------------------



}// end namespace acc

#endif // ACCELLIB_HPP_INCLUDED
