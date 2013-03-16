#include "rtty.h"

#define TX_PIN 7
#define RTTY_BAUD 300
#define STOP_BITS 2
#define REVERSED true
#define ECHO_TRANSMISSIONS true

AsynchronousRTTY rtty(TX_PIN, RTTY_BAUD, STOP_BITS, CHECKSUM_NONE, REVERSED,
        ECHO_TRANSMISSIONS);

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
    if(rtty.bufferSize() == 0) {
        char data[50] = "all your base are belong to us\r\n";
        rtty.transmitAsync(data);
    }
}
