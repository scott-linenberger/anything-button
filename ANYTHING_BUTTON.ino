#include <Arduino.h>
#include "StatusLed.h"
#include "Button.h"

/* pin declarations */
#define PIN_LED_GREEN 12
#define PIN_LED_BLUE 13
#define PIN_LED_RED 14
#define PIN_BUTTON 4

/* = BUTTON SETUP = */
/* time to wait between presses in ms */
uint16_t TIMEOUT_DEBOUNCE = 1000;

/* how long the button must be presse in ms */
uint16_t TIMEOUT_PRESS = 100;
boolean STATE_BUTTON_TRIGGERED = HIGH;

Button button = Button(
  PIN_BUTTON,
  TIMEOUT_DEBOUNCE,
  TIMEOUT_PRESS,
  STATE_BUTTON_TRIGGERED);

/* = STATUS LED SETUP = */
boolean ledOnState = LOW;

StatusLed statusLed = StatusLed(
  PIN_LED_RED,
  PIN_LED_GREEN,
  PIN_LED_BLUE,
  ledOnState
);

void setup() {
  /* begin serial for debugging */
  Serial.begin(115200);

  /* get pins ready */
  initPins();

  /* init objects */
  statusLed.begin();
  button.begin();
}

void initPins() {
  /* init RGB LED pins */
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_BLUE, OUTPUT);

  /* init button pin */
  pinMode(PIN_BUTTON, INPUT);
}

void loop() {
  if (button.isPressed()) {
    Serial.println("Pressed!");
    
    statusLed.red();
    delay(500);
    statusLed.off();
  }

  /* call the status LED's run method on each loop */
  statusLed.run();
}
