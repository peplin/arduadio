#define TX_PIN 3

// Thanks to Trackuino for this testing code
// http://www.trackuino.org/2010/04/audio-with-arduino-and-pwm.html
void setup() {
    // Configure pins
    pinMode(TX_PIN, OUTPUT);

    // Set up Timer 2 to do pulse width modulation on the speaker
    // pin.

    // Source timer2 from clkIO (datasheet p.164)
    ASSR &= ~(_BV(EXCLK) | _BV(AS2));

    // Set fast PWM mode with TOP = 0xff: WGM22:0 = 3  (p.150)
    TCCR2A |= _BV(WGM21) | _BV(WGM20);
    TCCR2B &= ~_BV(WGM22);

    // Do non-inverting PWM on pin OC2B (arduino pin 3) (p.159).
    // OC2A (arduino pin 11) stays in normal port operation:
    // COM2B1=1, COM2B0=0, COM2A1=0, COM2A0=0
    TCCR2A = (TCCR2A | _BV(COM2B1)) & ~(_BV(COM2B0) | _BV(COM2A1) | _BV(COM2A0));

    // No prescaler (p.162)
    TCCR2B = (TCCR2B & ~(_BV(CS22) | _BV(CS21))) | _BV(CS20);

    // Enable interrupt when TCNT2 reaches TOP (0xFF) (p.151, 163)
    TIMSK2 |= _BV(TOIE2);
}

int i = 0;
// Service routine for TIMER2's overflow interrupt.
// This is called at PLAYBACK_RATE Hz to load the next sample.
ISR(TIMER2_OVF_vect) {
    // [...] load the next sample
    OCR2B = i++;
    if(i >= 400) {
        i = 0;
    }
}

void loop() {
}
