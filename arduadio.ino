#include "rtty.h"

#define TX_PIN 7

#define RADIO_BAUD_RATE 50
#define STOP_BITS 1.5

RTTY rtty(TX_PIN, RADIO_BAUD_RATE, STOP_BITS, CHECKSUM_NONE);

void setup() {
    // initialize the digital pin as an output.
    pinMode(TX_PIN, OUTPUT);
}

void loop() {
    rtty.transmit("A");
    delay(1000);
}
