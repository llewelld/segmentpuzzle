/*
SegmentPuzzle
For the Adafruit Trinket
Cycles through a sequence of LED flashes.
Correctly arranged, they'll make a segment counter.

Based on Blink
13th December 2014
David Llewellyn-Jones - david[at]flypig.co.uk
Doris Benda - doris.benda[at]yahoo.de
*/

// The stripe to display
int stripe = 0;
// The digit shift
int digitShift = 0;

// Blink 'digital' pin 1 - AKA the built in red LED
int led = 1;

// The pattern used for each of the segments
/*

Shift 1    Shift 2
 --0--      --0--
|     |    |     |
1     2    1     2
|     1    |     |
 --3--      --3--
|     |    |     |
4     5    4     5
|     1    |     |
 --6--      --6--
*/
int stripePattern[7][10] = {
  {1, 0, 1, 1, 0, 1, 1, 1, 1, 1},
  {1, 0, 0, 0, 1, 1, 1, 0, 1, 1},
  {1, 1, 1, 1, 1, 0, 0, 1, 1, 1},
  {0, 0, 1, 1, 1, 1, 1, 0, 1, 1},
  {1, 0, 1, 0, 0, 0, 1, 0, 1, 0},
  {1, 1, 0, 1, 1, 1, 1, 1, 1, 1},
  {1, 0, 1, 1, 0, 1, 1, 0, 1, 1}
};

// The delay is calculated based on digitShift
int blinkDelay;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  // Set the delay base on the digit shift
  blinkDelay = 1000 / (1 << digitShift);
}

// the loop routine runs over and over again forever:
void loop() {
  // Loop through the blink patter
  for (int i= 0; i < 10; i++) {
    if (stripePattern[stripe][i] == 1) {
      // Light up! 
      digitalWrite(led, HIGH);
    }
    else {
      // Turn off
      digitalWrite(led, LOW);
    }
    // Stay like this for a bit
    delay(blinkDelay);
  } 
}

