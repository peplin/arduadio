#define TX_PIN 7

void setup() {
    // initialize the digital pin as an output.
    pinMode(TX_PIN, OUTPUT);
}

void loop() {
    digitalWrite(TX_PIN, HIGH);   // set the LED on
    delay(1000);              // wait for a second
    digitalWrite(TX_PIN, LOW);    // set the LED off
    delay(1000);              // wait for a second
}
