#include <LiquidCrystal.h>
#include <dhtnew.h>
DHTNEW DHT(7);
#define DHT11_PIN 2
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int enA = 10;
int in1 = 9;
int in2 = 8;
void setup()
{   
  pinMode(6,OUTPUT);
  lcd.begin(16,2);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  digitalWrite(in1, LOW);
	digitalWrite(in2, LOW);
  analogWrite(6,85);
}
void loop()
{


  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);  
  lcd.clear();
  int chk = DHT.read();
  int temp=DHT.getTemperature();
  int humi=DHT.getHumidity();
  lcd.setCursor(0,0);
  lcd.print("Temperature = ");
  lcd.println(temp);
  lcd.setCursor(0, 1);
  lcd.print("Humidity = ");
  lcd.println(humi);
  lcd.display();
  if(temp>=10 && temp<=20)
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(enA,0);
  }
  if((temp>=20 && temp<=34 )||humi<=45)
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(enA,100);
  }
  if(temp>=34 && temp<=45 || (humi>45 && humi<=55))
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(enA,180);
  }
  if(temp>=45 || humi>55)
  {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    analogWrite(enA,255);
  }


delay(3000);