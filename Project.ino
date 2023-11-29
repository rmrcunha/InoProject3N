#include <LiquidCrystal.h>

LiquidCrystal lcd(6, 7, 8, 9, 10, 11);
int buttonPinNext = 2;
int buttonPinPrev = 3;
int buttonPinStay = 4;
int buttonPinBack = 5;
int counter = 65;
unsigned int currentLocation = 0;

void setup() {
  lcd.begin(16, 2);
  pinMode(buttonPinNext, INPUT);
  pinMode(buttonPinPrev, INPUT);
  pinMode(buttonPinStay, INPUT);
  pinMode(buttonPinBack, INPUT);
}

void loop() {
  if (digitalRead(buttonPinNext) == LOW) {
    lcd.setCursor(currentLocation, 0);
    lcd.print((char)counter);
    counter++;
    delay(250);
  }
  if (digitalRead(buttonPinPrev) == LOW) {
    counter--;
    lcd.setCursor(currentLocation, 0);
    lcd.print((char)counter);
    delay(250);
  }
  if(digitalRead(buttonPinStay)==LOW){
    currentLocation++;
    lcd.setCursor(currentLocation, 0);
    delay(100);
  }
  if(digitalRead(buttonPinBack)==LOW){
    currentLocation--;
    lcd.setCursor(currentLocation, 0);
    delay(100);
  }
}
