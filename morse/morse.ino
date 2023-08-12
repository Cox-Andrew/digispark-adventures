#include <string>

const int map[26] = {
  0b10,
  0b0001,
  0b0101,
  0b001,
  0b0,
  0b0100,
  0b011,
  0b0000,
  0b00,
  0b1110,
  0b101,
  0b0010,
  0b11,
  0b01,
  0b111,
  0b0110,
  0b1011,
  0b010,
  0b000,
  0b1,
  0b100,
  0b1000,
  0b110,
  0b1001,
  0b1101,
  0b0011,
};

const string input = "HELLO";

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(1, OUTPUT); //LED on Model A
}

// the loop routine runs over and over again forever:
void loop() {
  for (int i = 0; i < input.length)
  digitalWrite(1, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(1000);               // wait for a second
  digitalWrite(1, LOW);   // turn the LED off by making the voltage LOW
  delay(1000);               // wait for a second
}

