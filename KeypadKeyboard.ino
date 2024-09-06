#include <Keypad.h>
#include "Keyboard.h"

const byte ROWS = 4;
const byte COLS = 4;

byte rowPins[ROWS] = { 2, 3, 4, 5 };
byte colPins[COLS] = { 6, 7, 8, 9 };

char customKeymap[ROWS][COLS] = {
  { '1', '2', '3', '4' },
  { 'a', 'b', 'c', 'd' },
  { 'k', 'l', 'm', 'n' },
  { 'u', 'v', 'w', 'x' }
};

Keypad keypad = Keypad(makeKeymap(customKeymap), rowPins, colPins, ROWS, COLS);

void setup() {
  
  Keyboard.begin();
}

void loop() {

  char key = keypad.getKey();
  int state = keypad.getState();

  if ( state!=0 ) { 
    Keyboard.press(key);} 
    
  else { 
    Keyboard.releaseAll();}
}
