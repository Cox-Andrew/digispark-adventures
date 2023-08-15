const int morse_map[26] = {
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

const int len = 16;
const char words[len] = "SOS";

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
  
  for (int i = 0; i < len; i++) {
    // check that we haven't reached the end of the string
    if (words[i] == '\0') break;
    // check if we have space character
    if (words[i] == ' ') {
      delay(7 * UNIT);
      continue;
    }

    int sequence = morse_map[words[i] - 'A'];

    while (sequence) {
      int is_dash = sequence & 1;
      sequence >>= 1;

      digitalWrite(1, HIGH);
      if (is_dash) {
        delay(3 * UNIT);
      } else {
        delay(UNIT);
      }
      digitalWrite(1, LOW);

      // delay between symbols (only if still same sequence)
      if (sequence) delay(UNIT);
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

