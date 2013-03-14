#include "rtty.h"
#include "emqueue.h"

#define TX_PIN 7

#define MAX_MESSAGE_LENGTH 255
#define RADIO_BAUD_RATE 110
#define STOP_BITS 1.5

RTTY rtty(TX_PIN, RADIO_BAUD_RATE, STOP_BITS, CHECKSUM_NONE, true);

QUEUE_DECLARE(uint8_t, 255);
QUEUE_DEFINE(uint8_t);

QUEUE_TYPE(uint8_t) rttyQueue;

void setup() {
    Serial.begin(115200);
    Serial.println("Initialized");
    QUEUE_INIT(uint8_t, &rttyQueue);
}

void loop() {
    if(QUEUE_EMPTY(uint8_t, &rttyQueue)) {
        char data[50] = "all your base are belong to us";
        int i = 0;
        while(data[i] != NULL) {
            QUEUE_PUSH(uint8_t, &rttyQueue, data[i]);
        }
    }

    if(!QUEUE_EMPTY(uint8_t, &rttyQueue)) {
        rtty.transmit(QUEUE_POP(uint8_t, &rttyQueue));
    }
}
