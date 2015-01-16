#include <iostream>
#include <vector>
#include "AccelLib.hpp"

/** \mainpage AccelLib Index Page
 * @author Henry J Schmale
 * @date January 15, 2015
 * \section intro_sec Introduction
 * This project's goal is to create an easy to use accelerometer / GPIO library
 * for single board computers.
 */

// Define Constants
const int ACCEL_CHANNELS = 4;
const gpio::GPIO_PIN_t CALIB_LIGHT = gpio::rPi::GPIO_10;
const gpio::GPIO_PIN_t CALIB_BUTTON = gpio::rPi::GPIO_11;
const gpio::GPIO_PIN_t SIG_LIGHT = gpio::rPi::GPIO_12;

// Define Globals
std::vector<acc::Rotate3d> accelRotations;


void init()
{
    // init Pins
    gpio::activatePin(CALIB_BUTTON);
    gpio::activatePin(CALIB_LIGHT);

    gpio::pinMode(CALIB_BUTTON, gpio::GPIO_INPUT);
    gpio::pinMode(CALIB_LIGHT, gpio::GPIO_OUTPUT);

    // init accelerometers
    //acc::initAccel3d(p1, p2, p3);
    //acc::initAccel3d(p4, p5, p6);
}

void eventLoop()
{

}

void endProg()
{
    // deactivate all pins
    gpio::deactivatePin(CALIB_BUTTON);
    gpio::deactivatePin(CALIB_LIGHT);

    // Do other shutdown things
    // deallocate the memory
}

int main()
{
    init();
    eventLoop();
    endProg();
    return 0;
}
