/*
 * B Donner Master Beispielprogramm
 * Version: 23.12.2023
 * Version auch auf dem esp32 getestet.
 * Standard-Pins esp32:
 * GPIO 21 (SDA)
 * GPIO 22 (SCL)
 * GND verbinden
 * ESP32 Wrover Kit auswählen
 * Achtung: Nicht jedes billige Micro USB Kabel ist für den ESP32 geeignet!
 */

// Include Arduino Wire library for I2C
#include <Wire.h>

// Define Slave I2C Address
#define SLAVE_ADDR 9

// Define Slave answer size
#define ANSWERSIZE 32 /* maximal mögliche ANSWERSIZE ist 32 */

void setup() {

  // Initialize I2C communications as Master
  Wire.begin();
  
  // Setup serial monitor
  Serial.begin(9600);
  Serial.println("Master Beispielprogramm");
}

void loop() {
  delay(50);

  /*---------------------------------------------------*/
  
  Serial.println("Master schickt Daten an den Slave");
  
  String msg = "Hey Sklave, putz mir die Schuhe!";

  // Write a String to the Slave
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(msg.c_str());
  Wire.endTransmission();
  Serial.print("Master schickt an Slave: ");
  Serial.println(msg);
    
  /*---------------------------------------------------*/  
  
  Serial.println("Master empfängt Daten");
  
  // Read response from Slave
  // Read back 5 characters
  Wire.requestFrom(SLAVE_ADDR, ANSWERSIZE);
  
  // Add characters to string
  String response = "";
  while (Wire.available()) {
      response += (char) Wire.read();
  } 
  
  // Print to Serial Monitor
  Serial.print("Master empfängt vom Slave: ");
  Serial.println(response);

  /*---------------------------------------------------*/  
}
