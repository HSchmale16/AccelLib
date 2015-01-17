#include <iostream>
#include <vector>
#include "AccelLib.h"

/** \mainpage AccelLib Index Page
 * @author Henry J Schmale
 * @date January 15, 2015
 * \section intro_sec Introduction
 * This project's goal is to create an easy to use accelerometer / GPIO library
 * for single board computers.
 */

#define A0 0
#define A1 1

using namespace std;

int main()
{
	acc::Accel accX1 = acc::initAccel(A0); // init by value
	acc::Accel accZ1;
	acc::initAccel(&accZ1, A1);
	cout << accZ1.m_id << " " << accX1.m_id;
	return 0;
}
