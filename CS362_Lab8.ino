//Gina Gerace, 664765515, ggerac3
//Lab 8: Arduino Interrupts
//This code shold use push buttons to start and stop interruptions.
//I assumed that pins 2 and 3 would work correctly for the interrupts.
//I used https://www.arduino.cc/en/Tutorial/HelloWorld, https://www.arduino.cc/en/tutorial/button,
//  and https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
//  as references.

// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 6, 7);

int button1 = 2;                //button to pause       
int button2 = 3;                //button to restart

unsigned long t = 0;            //will store the time in seconds
bool counting = true;           //false if in interrupt state

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Set the switch pins as input
  pinMode(button1, INPUT); 
  pinMode(button2, INPUT); 
  //attach interrupts to the button pins
  attachInterrupt(digitalPinToInterrupt(button1), buttonOne, CHANGE);
  attachInterrupt(digitalPinToInterrupt(button2), buttonTwo, CHANGE);
  delay(1000);                           //delay for one second
}

void loop() {
  if(counting == true){
    lcd.clear();
    lcd.setCursor(0,0);           //go to first line of lcd screen
    lcd.print(String(t) + " seconds");
    lcd.setCursor(0,1);           //go to second line of lcd screen
    lcd.print("spent waiting");
    t++;
    delay(1000);                  //delay for one second
  }
  else
    t = 0;
}

//if button 1 is pressed -> interrupt
void buttonOne() {
  counting = false;
  lcd.clear();
  lcd.setCursor(0,0);             //go to first line of lcd screen
  lcd.print("Interrupted!"); 
  lcd.setCursor(0,1);             //go to second line of lcd screen
  lcd.print("Press button 2");
}

//if button 2 is pressed -> start counting time again
void buttonTwo() {
  counting = true;
}
