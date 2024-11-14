#ifndef ATMOSPHERE_H
#define ATMOSPHERE_H

/// @brief Air gas constant. [J/(Kg.K)]
#define R_AIR_CONSTANT 287.058       

// #########################################################################################
// Library customization and configuration:

#define SENSOR_BMP180

// #########################################################################################
// Include libraries:

#include <Arduino.h>

#ifdef SENSOR_BMP180
  #include <Adafruit_BMP085.h>
#endif

// #########################################################################################

#ifdef SENSOR_BMP180

class Atmosphere_BMP180
{
  public:

    /// @brief Last error accured for object.
    String errorMessage;
    
    struct ParametersStructure
    {
      /// @brief Number of samples that is used for average calculations.
      uint8_t SAMPLE_USE;
    }parameters;

    struct ValuesStructure
    {
      /// @brief Temperature value. [Celcius]
      float temperature;

      /// @brief Pressure value. [Pa]
      float pressure;

      /// @brief Density value. [Kg/m^3]
      float density;

      /// @brief Altitude from mean sea level. [m]
      float altitude;
    }value;

    Atmosphere_BMP180();

    bool init(void);

    void update(void);

  private:

    Adafruit_BMP085 _sensor;

    bool _checkParameters(void);

};

#endif  // SENSOR_BMP180

// #####################################################################################

#endif  // ATMOSPHERE_H
