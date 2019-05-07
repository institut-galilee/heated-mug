#include <OneWire.h>
#include "SimpleBLE.h"

int DS18S20_Pin = 2;
OneWire ds(DS18S20_Pin);

SimpleBLE ble;
String beaconMsg = "ESP00";



void setup() {
    Serial.begin(115200);
    Serial.setDebugOutput(true);
}

void loop() {
    float temperature = getTemp();
    Serial.println(temperature);
    
      beaconMsg ="ESP"+String(temperature);
      Serial.println(beaconMsg);
      ble.begin(beaconMsg);
    
}

float getTemp(){
  

  byte data[12];
  byte addr[8];

  if ( !ds.search(addr)) {
      
      ds.reset_search();
      Serial.println("pas dadresse");
      return -1000;
  }

  ds.reset();
  ds.select(addr);
  ds.write(0x44,1);

  byte present = ds.reset();
  ds.select(addr);    
  ds.write(0xBE); 

  
  for (int i = 0; i < 9; i++) { 
    data[i] = ds.read();
  }
  
  ds.reset_search();
  
  byte a = data[1];
  byte b = data[0];

  float tempRead = ((a << 8) | b);
  float TemperatureSum = tempRead / 16;
  return TemperatureSum;
  
}
