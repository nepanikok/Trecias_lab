#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <LiquidCrystal.h> 
#include <Servo.h>

#define DHTPIN 5 
#define DHTTYPE DHT22 
DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal lcd(12, 11, 10, 9, 8, 7); 
Servo servoMotor;

const int pirPin = 6; 
int pirState = LOW; 
int lastPirState = LOW; 
unsigned long lastPirTime = 0; 

void setup() {
  
  lcd.begin(16, 2);

  dht.begin();

  pinMode(pirPin, INPUT);
  servoMotor.attach(4); 

  lcd.print("Temp: ");
  lcd.setCursor(0, 1);
  lcd.print("Humidity: ");
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  lcd.setCursor(6, 0);
  lcd.print(temperature);
  lcd.print(" C");

  lcd.setCursor(10, 1);
  lcd.print(humidity);
  lcd.print(" %");

  pirState = digitalRead(pirPin);

  if (pirState == HIGH && lastPirState == LOW) {
    lcd.clear();
    lcd.print("Motion Detected");
    lastPirTime = millis();
  }

  if (millis() - lastPirTime > 5000) {
    lcd.clear();
    lcd.setCursor(6, 0);
    lcd.print(temperature);
    lcd.print(" C");
    lcd.setCursor(10, 1);
    lcd.print(humidity);
    lcd.print(" %");
  }

  controlServo(humidity);

  lastPirState = pirState;
}

void controlServo(float humidity) {
  int servoAngle;

  if (humidity >= 0 && humidity < 15) {
    servoAngle = 0;
  } else if (humidity >= 15 && humidity < 30) {
    servoAngle = 45;
  } else if (humidity >= 30 && humidity < 50) {
    servoAngle = 90;
  } else if (humidity >= 50 && humidity < 75) {
    servoAngle = 140;
  } else {
    servoAngle = 180;
  }

  servoMotor.write(servoAngle);
  delay(1000);
}
