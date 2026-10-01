#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

#define SEN A0
#define RELAY 7

void setup() {
  pinMode(SEN, INPUT);
  pinMode(RELAY, OUTPUT);

  lcd.init();
  lcd.backlight();

  Serial.begin(9600);

  lcd.setCursor(0, 0);
  lcd.print("Irrigation Auto");
}

void loop() {
  int sensorValue = digitalRead(SEN);

  if (sensorValue == HIGH) {
    digitalWrite(RELAY, HIGH);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Soil Dry");
    lcd.setCursor(0, 1);
    lcd.print("Pump ON");
  } 
  else {
    digitalWrite(RELAY, LOW);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Soil Wet");
    lcd.setCursor(0, 1);
    lcd.print("Pump OFF");
  }

  delay(1000);
}
