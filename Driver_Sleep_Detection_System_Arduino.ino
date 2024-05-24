#include "Arduino.h"
#include "Buzzer.h"
#include "LiquidCrystal.h"
#include "LED.h"


// Pin Definitions
#define BUZZER_PIN_SIG	3
#define LCD_PIN_RS	9
#define LCD_PIN_E	8
#define LCD_PIN_DB4	4
#define LCD_PIN_DB5	5
#define LCD_PIN_DB6	6
#define LCD_PIN_DB7	7
#define LEDR_PIN_VIN	2



// Global variables and defines

// object initialization
Buzzer buzzer(BUZZER_PIN_SIG);
LiquidCrystal lcd(LCD_PIN_RS,LCD_PIN_E,LCD_PIN_DB4,LCD_PIN_DB5,LCD_PIN_DB6,LCD_PIN_DB7);
LED ledR(LEDR_PIN_VIN);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;
const int buzzer_Pin = 3;
const int led_Pin = 2;
char sleep_status = 0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    // set up the LCD's number of columns and rows
    lcd.begin(16, 2);
}
void loop() 
{
    while (Serial.available() > 0) 
  {
    sleep_status = Serial.read();
    if(sleep_status == 'a')
    { 
        lcd.clear();
        lcd.print("Please wake up");
        digitalWrite(buzzer_Pin, HIGH); 
        digitalWrite(led_Pin, HIGH);
        delay(2000);
        digitalWrite(buzzer_Pin, LOW); 
        digitalWrite(led_Pin, LOW);
        
        delay(100);
    }
    else if(sleep_status == 'b')
    {
        lcd.clear();
        lcd.print("All Ok");
        lcd.setCursor(0,2);
        lcd.print("Drive Safe");
        digitalWrite(buzzer_Pin, LOW); 
        digitalWrite(led_Pin, LOW);
        delay(2000);
    }
    else
    {
      /* Do Nothing */
    }
  }
}
