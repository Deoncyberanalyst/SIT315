// C++ code
//
int temp = 0;
int buttonState = 0;
int pirState = 0;


const int LED = A0;
const int sensor = A1;
const int buttonPin = 2;
const int pirSensor = 4;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(buttonPin, INPUT);  
  pinMode(pirSensor, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), ISR_action, CHANGE);
  
    Serial.begin(9600);
}

void loop()
{
  temp = analogRead(A1);
  pirState = digitalRead(pirSensor);

  if (temp > 200 || pirState == 1){
   		digitalWrite(LED, HIGH);
        Serial.print("PIR: ");
        Serial.print(String(pirState));
        Serial.print(" Temp: ");
        Serial.print(String(temp)); 
        Serial.println(" LED ON! ");
  } else { 
    	digitalWrite(LED, LOW);
        Serial.print("PIR: ");
        Serial.print(String(pirState));
        Serial.print(" Temp: ");
        Serial.print(String(temp));  
        Serial.println(". LED OFF!");
  }
  
  delay(200);
}

void ISR_action(){
  Serial.println("Interrupt!! Delay wont work inside an interrupt!");
  delay(50000);
}