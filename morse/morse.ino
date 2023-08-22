const int morse_map[26] = {
  0b110100,
  0b1100000001,
  0b1100010001,
  0b11000001,
  0b1100,
  0b1100010000,
  0b11000101,
  0b1100000000,
  0b110000,
  0b1101010100,
  0b11010001,
  0b1100000100,
  0b110101,
  0b110001,
  0b11010101,
  0b1100010100,
  0b1101000101,
  0b11000100,
  0b11000000,
  0b1101,
  0b11010000,
  0b1101000000,
  0b11010100,
  0b1101000001,
  0b1101010001,
  0b1100000101,
};

const int len = 16;
const char words[len] = "HELLO WORLD";

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(1, OUTPUT); //LED on Model A
}

// single unit of time delay for morse
#define UNIT 500

// the loop routine runs over and over again forever:
void loop() {
  // dot 1
  // dash 3
  // symbols 1
  // letters 3
  // words 7
  
  // iterate over the input string "words" one character at a time
  for (int i = 0; i < len; i++) {
    // check that we haven't reached the end of the string
    if (words[i] == '\0') break;
    // check if we have space character
    if (words[i] == ' ') {
      delay(7 * UNIT);
      continue;
    }

    // fetch the morse sequence from the map
    int sequence = morse_map[words[i] - 'A'];

    // iterate throught the morse symbols for this letter (until the end code 0b11)
    while (sequence != 0b11) {
      // check the final bit (dot/dash)
      int is_dash = sequence & 1;
      // shift by 2 bits (as we use 2-bits for each more symbol)
      sequence >>= 2;

      // LED on
      digitalWrite(1, HIGH);
      // stay on for appropriate duration
      if (is_dash) {
        delay(3 * UNIT);
      } else {
        delay(UNIT);
      }
      // LED off
      digitalWrite(1, LOW);

      // delay between symbols (only if still same sequence)
      if (sequence != 0b11) delay(UNIT);
    }

    // delay between letters (only if still same word)
    if (words[i+1] != ' ') delay(3 * UNIT);
  }

  // we did the message WOOO, flash, wait a bit, repeat
  for (int i = 0; i < 10; i++) {
    digitalWrite(1, HIGH);
    delay(50);
    digitalWrite(1, LOW);
    delay(50);
  }
  delay(14 * UNIT);
}

