#include <Arduino.h>
#include <Wire.h>

void setup() {
  Wire.setSCL(19);
  Wire.setSDA(18);
  Wire1.setSCL(16);
  Wire1.setSDA(17);
  Wire2.setSCL(24);
  Wire2.setSDA(25);

  Wire.begin();
  Wire1.begin();
  Wire2.begin();

  Serial.begin(9600);
  while(!Serial);
  Serial.println("\nI2C Scanner");
}

void loop() {
  byte error, address;
  int nDevices;

  Serial.println("Scanning...");

  nDevices = 0;
  for(address = 1; address < 127; address++ ) 
  {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknown error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }

    Wire1.beginTransmission(address);
    error = Wire1.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknown error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }
    
    Wire2.beginTransmission(address);
    error = Wire2.endTransmission();

    if (error == 0)
    {
      Serial.print("I2C device found at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.print(address,HEX);
      Serial.println("  !");

      nDevices++;
    }
    else if (error==4) 
    {
      Serial.print("Unknown error at address 0x");
      if (address<16) 
        Serial.print("0");
      Serial.println(address,HEX);
    }

  }

  if (nDevices == 0)
    Serial.println("No I2C devices found\n");
  else {
    Serial.print("Number of devices found = "); Serial.println(nDevices);
    Serial.println("done\n");
  }

  delay(1000);
}