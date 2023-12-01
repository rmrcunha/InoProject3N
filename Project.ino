#include <LiquidCrystal.h>

#define button A0

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int counter = 65;
unsigned int currentLocation = 0;

void setup() 
{
  lcd.begin(16, 2);
  pinMode(button, INPUT);
}

void loop() 
{
  Serial.println(analogRead(0));
  delay(100);
  if(analogRead(button)<80){
    currentLocation++;
    lcd.setCursor(currentLocation, 0);
    delay(100);
  }
  else if (analogRead(button) < 200) {
    lcd.setCursor(currentLocation, 0);
    lcd.print((char)counter);
    counter++;
    delay(250);
  }
  else if (analogRead(button) <400) {
    counter--;
    lcd.setCursor(currentLocation, 0);
    lcd.print((char)counter);
    delay(250);
  }
  else if(analogRead(button)<600){
    currentLocation--;
    lcd.setCursor(currentLocation, 0);
    delay(100);
  }
  
}
