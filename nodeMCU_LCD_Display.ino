// Displaying I2C LCD using Node MCU
// Made by Timotius Haniel, ITHB Electrical Eng. Student 2018.

#include <LiquidCrystal_I2C.h>

// Construct an LCD object and pass it the 
// I2C address, width (in characters) and
// height (in characters). Depending on the
// Actual device, the IC2 address may change.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // The begin call takes the width and height. This
  // Should match the number provided to the constructor.
  lcd.begin(16,2);
  lcd.init();
}

void loop() {
  int main = 1;
  while(main > 0){
    numberOneFunc();
    numberTwoFunc();
    blinkFunc();
  }
}

// numberOneFunc() is the function for Number one (Print Hello World)
int numberOneFunc(){
     lcd.backlight();
     lcd.setCursor(0, 0);
     lcd.print("HELLO WORLD");
     delay(3000);
     lcd.clear();
  }

// numberTwoFunc() is the function for number two (Print your name and NIM)
int numberTwoFunc(){
     lcd.setCursor(0, 0);
     lcd.print("TIMOTIUS HANIEL");
     lcd.setCursor(4, 1);      
     lcd.print("1418001");
     delay(3000);
     lcd.clear();
  }

// blinkFunc() is the function for number three (blinking the lcd backlight for every 2s)
int blinkFunc(){
     int blinkIndex = 0;
     for(blinkIndex=0;blinkIndex<4;blinkIndex++){
        lcd.setCursor(0, 0);
        lcd.print("TIMOTIUS HANIEL");
            
        lcd.setCursor(4, 1);      
        lcd.print("1418001");

        // Set the backlight on for 2s
        lcd.backlight();
        delay(2000);

        // Set the backlight off for 2s
        lcd.noBacklight();
        delay(2000);
       }
       lcd.clear();
 }
