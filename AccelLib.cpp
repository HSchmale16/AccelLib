/** Primary Implementation of AccelLib
 * @author Henry J Schmale
 * @date January 15, 2015
 */

#include "AccelLib.hpp"
#include <vector>
#include <fstream>

// Vector to containing accelerometers
static std::vector<acc::Accel3d> m_Accelerometers;

// ===================== Structs Ctor Implementation ==========================
acc::Accel3d::Accel3d(gpio::GPIO_PIN_t x, gpio::GPIO_PIN_t y,
                      gpio::GPIO_PIN_t z, int id)
    : m_id(id), m_xPin(x), m_yPin(y), m_zPin(z) {}

// ===================== Member Function Implementation =======================

