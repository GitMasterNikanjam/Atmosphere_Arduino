#include <Atmosphere.h>

Atmosphere_BMP180 atmosphere;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  
  atmosphere.parameters.SAMPLE_USE = 3;

  if(atmosphere.init() == false)
  {
    Serial.println(atmosphere.errorMessage);
    while(1);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  atmosphere.update();

  Serial.print("Temperature [celcius]: "); Serial.println(atmosphere.value.temperature);
  Serial.print("Pressure [pa]: "); Serial.print(atmosphere.value.pressure); 
  Serial.print("Density [Kg/m^3]: "); Serial.print(atmosphere.value.density); 
  Serial.print("Altitude [m]: "); Serial.println(atmosphere.value.altitude); 
  
  delay(100);
}
