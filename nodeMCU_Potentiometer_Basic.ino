#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);


String lcdTopLayer;
String lcdLowerLayer;
float voltage;
float miliVoltage;
int sensorValue;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  // Initialize LCD as the Output
  lcd.begin(16,2);
  lcd.init();
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  sensorValue = analogRead(A0);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  voltage = sensorValue * (5.0 / 1023.0);
  miliVoltage = voltage * 1000;
  
  serialMonitorDisplay();
  conditionData();
}

// Serial Monitor Output Function
int serialMonitorDisplay(){
  // Ultrasonic Sensor Data
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
  Serial.println(" ");
  delay(1500);
}

int conditionData(){
  lcd.clear();
  lcd.backlight();

  lcdTopLayer = "TIMOTIUS-1418001";
  lcd.setCursor(0, 0);
  lcd.print(lcdTopLayer);

  lcdLowerLayer = String(voltage);
  lcd.setCursor(0, 1);      
  lcd.print("Volt: "+lcdLowerLayer+" V");
}
