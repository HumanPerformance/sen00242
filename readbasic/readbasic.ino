
// Read Basic
//
// The following script has been written to demo the SHARP IR Proximity sensor
//
// Fluvio L Lobo Fenoglietto

int sensorPin = 0; //analog pin 0

void setup(){
  Serial.begin(9600); // specify the serial bitrate
}

void loop(){
  int val = analogRead(sensorPin); // read serial
  delay(100); // delay between readings
}
