#ifndef ACCELLIB_HPP_INCLUDED
#define ACCELLIB_HPP_INCLUDED

/** @file AccelLib.hpp
 * Primary Header for AccelLib
 * @author Henry J Schmale
 * @date January 15, 2015
 */

/// Functions to work with accelerometers live here!!
namespace acc
{

// ========================= Structs ==========================================

/** \brief Struct to hold values of a 3d accelerometer
 *
 * This struct is used to update the values of accelerometers. As well as check
 * the standard deviation from baseline
 */
struct Accel3d
{
    int m_id;   /**< Id of that accelerometer */
    // Pins
    int m_xPin; /**< Pin to read x-axis from */
    int m_yPin; /**< Pin to read y-axis from */
    int m_zPin; /**< Pin to read z-axis from */
    // Rotation
    int m_xRot; /**< Rotation on x-axis */
    int m_yRot; /**< Rotation on y-axis */
    int m_zRot; /**< Rotation on z-axis */

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
int initAccel3d(int x_pin, int y_pin, int z_pin);

/** \brief Reads an accelerometer and  returns a modified struct containing the
    data about that accelerometer
 * \param a3d - the struct to be modified
 * \param id - id number of that accelerometer
 * \return 0 on success
 *
 */
int readAccel3d(Accel3d *a3d, int id);


/** \brief updates an Accel3d instances based on the m_id
 * \param A3d - Accel3d instances to update
 * \return 0 on success,
 */
int updateAccel3d(Accel3d *a3d);


}// end namespace acc

#endif // ACCELLIB_HPP_INCLUDED
