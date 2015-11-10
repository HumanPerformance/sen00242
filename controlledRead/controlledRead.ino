// CONTROLLED READ
//
// The following script was built to allow users to collect a preset number of readings from the sensor connected to the Arduino board.
// The script requires some variables to be hard-coded into the script
//
// Fluvio L. Lobo Fenoglietto

// VARIABLES

// Static variables -- Variables that do not change throughout the code
int sensorPin = 0; //reference to analog pin 0 (A0)
const int numberofReads = 100; //reference to the number of measurements taken from the connected sensor
int outputArray[numberofReads]; //initialize sensor data array - sized by 'numberofReads'

// Dynamic variables -- Variables that do change throughout the code


void setup() {
  
  // setup routines
  Serial.begin(9600);
  while (! Serial);
  
  // Initial Message:
  Serial.println("controlledRead.ino");
  Serial.println("WELCOME!");
  // START REC.
  Serial.println("To begin recording sensor data type '1' and press [Enter] or {Send} on the serial monitor");
  
}

// MAIN PROGRAM LOOP
void loop() {
  
  if (Serial.available()) {
    
    sensordataRead();   
    
  }// End 'if-statement'
  
}// End 'void-loop'


// PROGRAM SUBFUNCTIONS AND EXECUTIONS

// Sensor Read
// The following sub-routine generates and populates and array with sesnor measurements
void sensordataRead() {

  int resp = Serial.read();
  int expected = '1';  
  
  if (resp == expected) {
    
    Serial.println("START RECORDING");
    
    int i;   
    for (i = 0; i < numberofReads; i++) {
      
      int counter = i;
      int sensorVal = analogRead(sensorPin);
        
      outputArray[i] = sensorVal;
        
      String separator = ", ";
      String outputString = counter + separator + sensorVal;
      Serial.println(outputString);

      delay(100); // purposely delay recording

      if (i == 99) {

        Serial.println("Data read completed");

        arrayAvg(outputArray);
        
        Serial.println("To begin reading again, neter '1' into the serial monitor window...");
          
      } // End of 'if-statement'
      
    } // End of 'for-loop'
    
  } // End of 'if?'  

} // End of 'sensordataRead'

// Array Average
// The following sub-routine calculates the average of all the elements contained within a vector
void arrayAvg(int outputArray[]) {

  int arrayLength = sizeof(outputArray[]);
  Serial.println(arrayLength);
  
  int i;
  int sum = 0;  
  for (i = 0; i < arrayLength; i++) {
    
    sum = sum + outputArray[i];
    Serial.println(sum);
    
  }// End of 'for-loop'
  
}// End of 'arrayAvg'

