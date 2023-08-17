// C++ code
const int LED = 13;
const int LED_G = 12;
const int TMP = A1;
const int BUTTON = 3;
const int PIR = 2;
volatile bool pirState = 0;


void setup()
{
  	pinMode(LED, OUTPUT);
 	pinMode(LED_G, OUTPUT);
  	pinMode(TMP, INPUT);
 	pinMode(BUTTON, INPUT);
  	pinMode(PIR, INPUT);
	Serial.begin(9600);
  	attachInterrupt(digitalPinToInterrupt(BUTTON), ISR_action, RISING  );
	attachInterrupt(digitalPinToInterrupt(PIR), ISR_action2, RISING);

  //Info from Arduino official docs
  //Typically global variables are used to pass data between
  //an ISR and the main program. To make sure variables shared
  //between an ISR and the main program are updated correctly,
  //declare them as volatile.
  
  //RISING to trigger when the pin goes from low to high,
}

void loop()
{
  	Serial.println("Temperature is:" + String(analogRead(TMP)) + "\n");
	delay(5000);
}


void ISR_action(){
  	analogRead(TMP)>200 ? digitalWrite(LED, HIGH) : digitalWrite(LED, LOW);
  	analogRead(TMP)>200 ? Serial.println("BLUE LED ON!") : Serial.println("BLUE LED OFF!");
}

void ISR_action2(){
  	pirState = !pirState;
  	pirState ? Serial.println("GREEN LED ON") : Serial.println("GREEN LED OFF");
	digitalWrite(LED_G, pirState);
}