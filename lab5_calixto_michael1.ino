
// include the library code:
#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
const int BlueLED = 13;
const byte interruptPin =2;
volatile byte state = LOW;

int timer1=0;


void loop() 
{
  init_function();
  update_lcd();
  blink_LED();
  timers();

}
void init_function()
{
  
  attachInterrupt(digitalPinToInterrupt(interruptPin),blink,CHANGE);
}
void update_lcd(void)
{
  lcd.begin(16,2);
  lcd.print("hello, world!");
  lcd.setCursor(0,1);
  lcd.print(millis()/1000);
}
void blink_LED(void)
{
  if(timer1<0)
    BlueLED = 1;
  else if (timer1<10)
    BlueLED = 0;
    else 
    timer1=0;
    
}
void timers(void)
{
  timer1++;
}

