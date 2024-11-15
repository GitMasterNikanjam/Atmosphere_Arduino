
// #############################################################################################
// Include libraries:

#include "Atmosphere.h"

// #############################################################################################
// Private Macros:

/// @brief Air gas constant. [J/(Kg.K)]
#define R_AIR_CONSTANT 287.058 

/// @brief Offset conversion value for convert celcius to kelvin degree. C = K + Celcius2Kelvin.
#define Celcius2Kelvin  273.15

// #############################################################################################
// SENSOR_BMP180:

#ifdef SENSOR_BMP180

Atmosphere_BMP180::Atmosphere_BMP180()
{
  parameters.SAMPLE_USE = 1;

  value.altitude = 0;
  value.density = 0;
  value.pressure = 0;
  value.temperature = 0;
}

bool Atmosphere_BMP180::init(void)
{
  if(_checkParameters() == false)
  {
    errorMessage = "Error Atmosphere_BMP180: One or some parameters are not correct.";
    return false;
  }

  if(!_sensor.begin()) 
  {
	  errorMessage = "Error AtmosphereBMP180: Could not find a valid BMP180 sensor, check wiring!";
    return false;
  }

  return true;
}

void Atmosphere_BMP180::update(void)
{
    float _temperature = 0;
    float _pressure = 0;
    float _altitude = 0;
  
    for(int i=1; i <= parameters.SAMPLE_USE; i++)
    {
      _temperature += (_sensor.readTemperature()/(float)parameters.SAMPLE_USE);
      _pressure += (_sensor.readPressure()/(float)parameters.SAMPLE_USE);
      _altitude += (_sensor.readAltitude()/(float)parameters.SAMPLE_USE);
    }
    
    value.temperature = _temperature;
    value.pressure = _pressure;
    value.altitude = _altitude;
    value.density = _pressure/(R_AIR_CONSTANT * (_temperature + Celcius2Kelvin));      // Density = P / (R * T)
}

bool Atmosphere_BMP180::_checkParameters(void)
{

  return true;
}

#endif  // SENSOR_BMP180

// #########################################################################################################################