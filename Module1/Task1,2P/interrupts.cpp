// C++ code
//
int temp = 0;
int buttonState = 0;

const int LED = A0;
const int sensor = A1;
const int buttonPin = 2;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(sensor, INPUT);
  pinMode(buttonPin, INPUT);  
  attachInterrupt(digitalPinToInterrupt(2), ISR_action, CHANGE);
  
    Serial.begin(9600);
}

void loop()
{
  temp = analogRead(A1);
  Serial.print("Temperature value: " + String(temp) + " " );
  if (temp > 200){
    digitalWrite(LED, HIGH);
    Serial.println("LED ON!");
  	} else { 
    digitalWrite(LED, LOW);
    Serial.println("LED OFF!");
  }
  
  delay(200);
}

void ISR_action(){
  Serial.println("Interrupt!! Delay wont work inside an interrupt!");
  delay(50000);
}