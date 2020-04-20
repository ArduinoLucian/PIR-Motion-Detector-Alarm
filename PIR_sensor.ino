/*
   PIR sensor tester
*/
#include "pitches.h";
int ledPin = 13;                // choose the pin for the LED
int inputPin = 2;               // choose the input pin (for PIR sensor)
int PIRoutput = 9;
int val = 0;   // variable for reading the pin status
int i = 0;

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare sensor as input
  pinMode(PIRoutput, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {
    digitalWrite(ledPin, HIGH);
    for (i = 0; i < 1500; i++) {
      tone(PIRoutput, 100 + i);
    }
  }
  else {
    noTone(PIRoutput);
    digitalWrite(ledPin, LOW);
  }
}
