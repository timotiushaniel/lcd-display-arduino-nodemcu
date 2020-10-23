#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

// defines pins numbers

const int trigPin = 2;  //D4
const int echoPin = 0;  //D3

// defines variables
long duration;
int distance;
String lcdTopLayer;
String lcdLowerLayer;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

  // Initialize LCD as the Output
  lcd.begin(16,2);
  lcd.init();
}

void loop() {
  ultraSonicDistance();
  serialMonitorDisplay();
  conditionData();
}

int ultraSonicDistance(){
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;  
}

// Serial Monitor Output Function
int serialMonitorDisplay(){
  // Ultrasonic Sensor Data
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" Cm");
  Serial.println(" ");
  delay(1500);
}

int conditionData(){
  lcd.clear();
  lcd.backlight();

  lcdTopLayer = "TIMOTIUS-1418001";
  lcd.setCursor(0, 0);
  lcd.print(lcdTopLayer);

  lcdLowerLayer = String(distance);
  lcd.setCursor(0, 1);      
  lcd.print("Jarak: "+lcdLowerLayer+" Cm");
}
