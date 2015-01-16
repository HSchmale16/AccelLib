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
const int

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

	Accel(int pin); /**< inits an accelerometer instance */
};

// ========================= Functions =======================================



}// end namespace acc

#endif // ACCELLIB_HPP_INCLUDED
