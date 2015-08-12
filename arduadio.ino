#include "rtty.h"

#define ENABLE_PIN 3
#define TX_PIN 7
#define RTTY_BAUD 1200
#define STOP_BITS 2
#define REVERSED true
#define ECHO_TRANSMISSIONS true
#define ASCII_BITSIZE 7

AsynchronousRTTY rtty(ENABLE_PIN, TX_PIN, RTTY_BAUD, STOP_BITS, ASCII_BITSIZE,
        CHECKSUM_NONE, REVERSED, ECHO_TRANSMISSIONS);

String message;

uint32_t rttyTransmitInterrupt(uint32_t currentTime) {
    rtty.transmitInterrupt();
    return (currentTime + CORE_TICK_RATE * (1.0 / RTTY_BAUD * 1000.0));
}

void setup() {
    Serial.begin(115200);
    Serial.println("Initialized");
    attachCoreTimerService(rttyTransmitInterrupt);
}

void loop() {
    while (Serial.available() > 0) {
        char received = Serial.read();
        Serial.print(received);
        message += received;
    }

    if(message.indexOf("\r") != -1 && rtty.bufferSize() == 0) {
        Serial.println("");
        Serial.println("Sending " + message);
        char data[500] = {};
        message.toCharArray(data, sizeof(data));
        message = "";
        rtty.transmitAsync(data);
        Serial.print("Message to send: ");
    }
}
