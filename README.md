# <Atmosphere.h> library for Arduino

- This library can be used to measure atmosphere properties by variaty of sensors.  
- User can select and customize which sensors that want to use.   
- Each model type sensor has its own class.   

## "Atmosphere_BMP180" Class

### Public Member Functions

```c++

/**
      @brief Init object. Check parameters.
      @return true if succeeded.
    */
    bool init(void);

    /**
      @brief Read and update values of object.
    */
    void update(void);

```

### Public Member Variables

```c++

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

```