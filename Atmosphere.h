#ifndef ATMOSPHERE_H
#define ATMOSPHERE_H

// #########################################################################################
// Public Macros:

    

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
    
    /**
      @struct ParametersStructure
      @brief Parameters structure.
    */
    struct ParametersStructure
    {
      /// @brief Number of samples that is used for average calculations.
      uint8_t SAMPLE_USE;
    }parameters;

    /**
      @struct ValuesStructure
      @brief Values structure.
    */
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

    /// @brief Default constructor. Init some variables and parameters.
    Atmosphere_BMP180();

    /**
      @brief Init object. Check parameters.
      @return true if succeeded.
    */
    bool init(void);

    /**
      @brief Read and update values of object.
    */
    void update(void);

  private:

    /// @brief The object for BMP085/BMP180 sensor from https://github.com/adafruit/Adafruit-BMP085-Library.git
    Adafruit_BMP085 _sensor;

    /**
      @brief Check parameters validation.
      @return true if succeeded.
    */
    bool _checkParameters(void);

};

#endif  // SENSOR_BMP180

// #####################################################################################

#endif  // ATMOSPHERE_H
