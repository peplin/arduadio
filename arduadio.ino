#include "rtty.h"

#define TX_PIN 7

#define RADIO_BAUD_RATE 110
#define STOP_BITS 1.5

RTTY rtty(TX_PIN, RADIO_BAUD_RATE, STOP_BITS, CHECKSUM_NONE, true);

void setup() {
    Serial.begin(115200);
    Serial.println("Initialized");
}

void loop() {
    char data[50] = "all your base are belong to us";
    rtty.transmit(data);
}
