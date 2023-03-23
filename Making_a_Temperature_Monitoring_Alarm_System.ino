#include<Servo.h>
Servo gateServo;
int inpin=A1;
int Redled=10;
int Blueled=11;
int buzzer=9;
int adc_val;
float eq_val;
float temp_val;
void setup()
{
  Serial.begin(9600);
  gateServo.attach(8);
  pinMode(buzzer,OUTPUT);
  pinMode(Redled,OUTPUT);
  pinMode(Blueled,OUTPUT); 
}
void loop()
{
  adc_val=analogRead(inpin);
  Serial.println(adc_val);
  eq_val=adc_val*4.88;
  Serial.println(eq_val);
  temp_val=(eq_val-500)/10;
  Serial.println(temp_val);
  if(temp_val<15)
  {
    digitalWrite(buzzer,HIGH);
    digitalWrite(buzzer,LOW);
    digitalWrite(Redled,HIGH);
    digitalWrite(Redled,LOW);
    gateServo.write(0);
  }
  else if(temp_val>100)
  {
    digitalWrite(buzzer,HIGH);
    digitalWrite(buzzer,LOW);
    digitalWrite(Blueled,HIGH);
    digitalWrite(Blueled,LOW);
    gateServo.write(180);
  }
  else
  {
    gateServo.write(90);
  }
  delay(100);  
}
