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

    // Initializing Dynamic Variable - Variables to change with each loop
    int i; // loop counter
    float sumReads = 0; // sum of all sensor readings
    float readAvg = 0; // average of added readings
    
    for (i = 0; i < numberofReads; i++) {
      
      int counter = i;

      int sensorVal = analogRead(sensorPin); //reading sensor output  
         
      String separator = ", ";
      String outputString = counter + separator + sensorVal;
      Serial.println(outputString); //displaying sensor output in serial monitor

      sumReads = sumReads + (float)sensorVal; //addition of sensor output values

      delay(10); // purposely delay recording

      if (i == numberofReads-1) {

        Serial.println("Data read completed");

        readAvg = sumReads/(float)numberofReads; //average of sensor readings
        String initiator = "The average reading was: ";
        String outputString = initiator + readAvg; 
        Serial.println(outputString);
        
        Serial.println("To begin reading again, neter '1' into the serial monitor window...");
          
      } // End of 'if-statement'
      
    } // End of 'for-loop'
    
  } // End of 'if-statement'  

} // End of 'sensordataRead'


