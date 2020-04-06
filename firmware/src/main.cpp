#include <Arduino.h>
#include <MCP335X.h>
#include <AM2320.h>
#include <MQ131.h>

AM2320  thSensor(&Wire);
MCP335X adc(10, 11, 12, 13);
MQ131   mq131(MQ131Model::HighConcentration, &adc, &thSensor); 
boolean thSenseFound = false;
boolean ozSenseFound = false;

void setup(){
  Serial.begin(115200);
  adc.begin();
  thSensor.begin();
  mq131.begin(); // this will NOT call adc.begin() and th.begin()!
  mq131.calibrate();
}

void loop(){
	mq131.read();
	float o3 = mq131.getO3();
	Serial.print("O3: "); Serial.print(o3); Serial.println(" PPM");
	delay(500);
    //adc.read();
    //thSensor.read();
    //Serial.print("O3: "); Serial.println(adc.getLastValue());
    //Serial.print("TC: "); Serial.println(thSensor.getTemperature());
    //Serial.print("RH: "); Serial.println(thSensor.getHumidity());
}
