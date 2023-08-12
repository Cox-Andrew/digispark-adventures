#include "DigiKeyboard.h"
void setup() {
  // Enable LED pin
  pinMode(1, OUTPUT);
}
void loop() {
  // Init keyboard
  DigiKeyboard.sendKeyStroke(0);

  // Windows run
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);

  // Open tutorial
  DigiKeyboard.print("chrome bit.ly/3PSFtMz");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  
  for(;;){
    digitalWrite(1, HIGH);
    delay(500);
    digitalWrite(1, LOW);
    delay(500);
  }
}
