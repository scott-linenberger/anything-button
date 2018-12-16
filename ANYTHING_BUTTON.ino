#include <Arduino.h>

/* pin declarations */
#define PIN_LED_GREEN 12
#define PIN_LED_BLUE 13
#define PIN_LED_RED 14
#define PIN_BUTTON 4

void setup() {
  /* begin serial for debugging */
  Serial.begin(115200);

  /* get pins ready for use */
  initPins();
}

void initPins() {
  /* init RGB LED pins */
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_BLUE, OUTPUT);

  /* init button pin */
  pinMode(PIN_BUTTON, INPUT);
}

void ledStatusOff() {
  /* turn R, G and B off */
  digitalWrite(PIN_LED_RED, HIGH);
  digitalWrite(PIN_LED_GREEN, HIGH);
  digitalWrite(PIN_LED_BLUE, HIGH);
}

void loop() {

}
