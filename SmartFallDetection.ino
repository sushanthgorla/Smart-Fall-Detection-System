#include <Wire.h>
#include <MPU6050.h>
#include <LiquidCrystal.h>

MPU6050 mpu;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int buzzerPin = 8;
const float FALL_THRESHOLD = 0.5;
bool fallDetected = false;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu.initialize();

  pinMode(buzzerPin, OUTPUT);
  lcd.begin(16, 2);
  lcd.print("Initializing...");
  delay(1000);

  if (mpu.testConnection()) {
    Serial.println("MPU6050 connected.");
    lcd.clear();
    lcd.print("MPU6050 Ready");
  } else {
    Serial.println("MPU6050 connection failed!");
    lcd.clear();
    lcd.print("Sensor Error!");
    while (1);
  }

  delay(1500);
  lcd.clear();
  lcd.print("Monitoring...");
}

void loop() {
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);

  float acc = sqrt(ax * ax + ay * ay + az * az) / 16384.0;

  Serial.print("Accel: ");
  Serial.println(acc);

  if (acc < FALL_THRESHOLD && !fallDetected) {
    fallDetected = true;
    triggerFall();
  }

  delay(200);
}

void triggerFall() {
  lcd.clear();
  lcd.print("Fall Detected!");
  Serial.println("Fall Detected!");

  digitalWrite(buzzerPin, HIGH);
  delay(5000);
  digitalWrite(buzzerPin, LOW);

  lcd.clear();
  lcd.print("Monitoring...");
  fallDetected = false;
}
