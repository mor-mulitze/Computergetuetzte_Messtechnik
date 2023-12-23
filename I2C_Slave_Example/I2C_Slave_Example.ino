/*
 * B Donner Slave Beispielprogramm
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


void setup() {

  // Initialize I2C communications as Slave
  Wire.begin(SLAVE_ADDR);
  
  // Function to run when data requested from master
  Wire.onRequest(requestEvent); 
  
  // Function to run when data received from master
  Wire.onReceive(receiveEvent);
  
  // Setup Serial Monitor 
  Serial.begin(9600);
  Serial.println("Slave Beispielprogramm");
}



void receiveEvent(int ich_bin_sowas_von_unwichtig) {
  Serial.println("Slave Receive event");

  String masterstring = "";

  // Read while data received
  while (Wire.available()) {
    masterstring += (char) Wire.read();   /* masterstring = masterstring + Wire.read(); */
  }
  
  // Print to Serial Monitor
  Serial.print("Slave empfängt vom Master: ");
  Serial.println(masterstring);
}



void requestEvent() {
  String answer = "Bin kein Sklave, ich bin frei!!!";

  Serial.println("Slave Request event");
  // Send response back to Master
  Wire.write(answer.c_str());
  Serial.print("Slave antwortet mit: ");
  Serial.println(answer);
  
  
}

void loop()
{
  // Time delay in loop
  delay(50);
}
