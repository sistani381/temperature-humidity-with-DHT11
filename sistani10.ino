#include<LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
#include "DHT.h"// DHT LIBRARY 
#define DHTPIN 8//digital pin connected to DHT11
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  dht.begin();
  lcd.begin(16, 2); 
  pinMode(DHTPIN, INPUT);
}

void loop() {
  float humid = dht.readHumidity();//read humidity from sensor
  float temp = dht.readTemperature();//read temperature from sensor
  lcd.setCursor(0, 0);
  lcd.print("temp =");
  lcd.print(temp);
  lcd.print("*c");
  lcd.setCursor(0, 1);
  lcd.print("humid = ");
  lcd.print(humid);
  lcd.print("%");
  delay(500);//waits for 500 ms
  lcd.clear();
  
}
