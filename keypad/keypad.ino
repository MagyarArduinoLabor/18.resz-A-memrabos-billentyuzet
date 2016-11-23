/* @file HelloKeypad.pde
|| @version 1.0
|| @author Alexander Brevig
|| @contact alexanderbrevig@gmail.com
||
|| @description
|| | Demonstrates the simplest use of the matrix Keypad library.
|| #
*/
#include <Keypad.h>

int zold_led = 10;
int piros_led = 11;

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns
char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 7, 6}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup(){

  pinMode(zold_led,OUTPUT);
  pinMode(piros_led,OUTPUT);
  
  Serial.begin(9600);
}
  
void loop(){
  char key = keypad.getKey();
  
  if (key)
  {
    if(key == '1')
    {
      digitalWrite(zold_led, HIGH);
      digitalWrite(piros_led, LOW);
    }
    if(key == '2')
    {
      digitalWrite(zold_led, LOW);
      digitalWrite(piros_led, HIGH);
    }
    if(key == '3')
    {
      digitalWrite(zold_led, HIGH);
      digitalWrite(piros_led, HIGH);
    }
    if(key == '#')
    {
      digitalWrite(zold_led, LOW);
      digitalWrite(piros_led, LOW);
    }
    
    Serial.println(key);
  }
}
