// C++ code
const int LED = 13;
const int TMP = A1;
int BUTTON = 3;

void setup()
{
  	pinMode(LED, OUTPUT);
  	pinMode(TMP, INPUT);
 	pinMode(BUTTON, INPUT);
	Serial.begin(9600);
  	attachInterrupt(digitalPinToInterrupt(3), ISR_action, FALLING);
  
  //FALLING for when the pin goes from high to low.
}

void loop()
{
  	Serial.println("Temperature is:" + String(analogRead(TMP)));
	delay(5000); 
}


void ISR_action(){
  analogRead(TMP)>200 ? digitalWrite(LED, HIGH) : digitalWrite(LED, LOW);
}