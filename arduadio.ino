#include "rtty.h"

#define TX_PIN 7

#define RADIO_BAUD_RATE 50
#define STOP_BITS 1.5

RTTY rtty(TX_PIN, RADIO_BAUD_RATE, STOP_BITS, CHECKSUM_NONE);

void setup() {
    Serial.begin(115200);
    Serial.println("Initialized");
}

void loop() {
    Serial.println("Sent");
    char data[20] = "A";
    rtty.transmit(data);
    delay(1000);
}
