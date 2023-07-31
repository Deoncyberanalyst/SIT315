// C++ code
//
int temp = 0;

void setup()
{
  pinMode(A0, OUTPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop()
{
  temp = analogRead(A1);
  Serial.println("Temperature value: " + String(temp));
 
  if (temp > 200){
    digitalWrite(A0, HIGH);
    Serial.println("LED ON!");
  } else { 
    digitalWrite(A0, LOW);
    Serial.println("LED OFF!");
  }
  
  delay(200);
}