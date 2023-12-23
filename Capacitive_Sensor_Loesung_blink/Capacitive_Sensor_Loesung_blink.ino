#include <CapacitiveSensor.h>
CapacitiveSensor Sensor = CapacitiveSensor(4, 6);
long val;
bool led_status = false;
#define led 13

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop()
{
  val = Sensor.capacitiveSensor(30);
  Serial.println(val);
  
  if (val >= 1000) {
    led_status = !led_status;
    
    digitalWrite(led, led_status);
    delay(1000);
  }

  else if (val < 1000) {
    led_status = false;
    digitalWrite(led, led_status);   
  }

  delay(10);
}
