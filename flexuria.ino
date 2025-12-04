#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

int readFlexSensor(int pin) {
  int total = 0;
  const int samples = 15;

  for (int i = 0; i < samples; i++) {
    total += analogRead(pin);
    delay(5);
  }
  return total / samples;
}

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}

void loop() {

  int sensorValueOne = readFlexSensor(A3);
  int sensorValueTwo = readFlexSensor(A2);
  int sensorValueThree = readFlexSensor(A1);

  String word1 = "_";
  String word2 = "_";
  String word3 = "_";

  // Sensor 1
  if  {
    (sensorValueOne > 900)       word1 = "I";
  }
  else if {
    (sensorValueOne > 650)  word1 = "You";
  }
  else if (sensorValueOne > 200)  word1 = "Yes!";



  // Sensor 2
  if {
    (sensorValueTwo > 900)       word2 = "want";
  }
  else if {
    (sensorValueTwo > 650)  word2 = "this";
  }
  else if (sensorValueTwo > 200)  word2 = "will";

  if{
    (sensorValueTwo == 676) word2 = "link";
  }


  // Sensor 3
  if {
    (sensorValueThree > 900)     word3 = "stop";
  }
  else if {
    (sensorValueThree > 650) word3 = "help";
  }
  else if {
    (sensorValueThree > 200) word3 = "not";
  }


  // Build full line
  String line = word1 + " " + word2 + " " + word3;

  // Print to LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(line);

  // Print to Serial
  Serial.println(line);

  delay(1500);
}
