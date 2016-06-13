#ifndef ISA_H_INCLUDED
#define ISA_H_INCLUDED

#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

/*! \file ISA.h 
\brief Main International Standard atmosphere states
*/

//! \class ISA class
/*! This class allows to define the International Standard Atmosphere up to the Stratosphere. 
Check within its methods for different atmospheric data.
*/
class ISA
{
private:
    double rhoSL; /*!< ISA density at sea level 1,225 kg/m^3 */
    double TSL; /*!< ISA Temperature at sea level, 288 K */
    double pSL; /*!< ISA pressure at sea level, 101325 Pa */
    double Rair; /*!< R for air*/
    double gamma; /*!< cp over cv ratio for air */
    double g; /*!< gravity */
    double dTdz; /*!< vertical temperature lapse */
public:
    ISA();
	/*!\fn double pressure(double h) 
	\brief returns the pressure in Pascal
	\param h altitude in meters
	\return pressure at high h in Pa
	*/
    double pressure(double h); 

	/*!\fn double temperature(double h) returns the temperature in Kelvin
	\param h altitude in meters
	\return Temperature at high h in K
	*/
    double temperature(double h);

	/*!\fn double density(double h) returns the density in kg/m^3
	\param h altitude in meters
	\return density at high h in kg/m^3
	*/
    double density(double h);
    
	/*!\fn double asound(double h) returns the speed of sound in m/s
	\param h altitude in meters
	\return speed of sound at high h in m/s
	*/
	double asound(double h);

	/*!\fn void print() prints to screen the ISA up to 20000 meters
	*/
    void print();

	/*!\fn double ft2m(double hft) converts ft to meters
	\param hft height in feet
	\return height in meters
	*/
    double ft2m(double hft);

	/*!\fn double m2ft(double hm) converts meters to feet
	\param hm height in meters
	\return height in feet
	*/
    double m2ft(double hm);
};


#endif // ISA_H_INCLUDED
