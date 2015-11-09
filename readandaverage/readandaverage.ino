
// The following script has been designed to interface with the SHARP IR Proximity sensor sen00242
// 1 - The script allows for the user to display sensor readings in the Arduino serial monitor
// 2 - The script averages the readings of the sensors
//
// Fluvio L. Lobo Fenoglietto - 11092015 -

int sensorPin = 0; //analog pin 0

void setup(){
  Serial.begin(9600);
}

void loop(){

  int outputArray[100];
  
  for (int i = 0; i < 100; i++) {

    outputArray[i] = analogRead(sensorPin);
    Serial.println(outputArray[i]);
    
    
  }

  //just to slow down the output - remove if trying to catch an object passing by
  delay(100);

}
