/* include the configuration file */
#include "config.h"

/* include required Arduino libs */
#include <Arduino.h>
#include "AdafruitIO_WiFi.h"

/* include custom classes */
#include "StatusLed.h"
#include "Button.h"

/* = BUTTON SETUP = */
/* time to wait between presses in ms */
uint16_t TIMEOUT_DEBOUNCE = 1000;

/* how long the button must be presse in ms */
uint16_t TIMEOUT_PRESS = 100;
boolean STATE_BUTTON_TRIGGERED = HIGH;

/* Adafruit IO settings */
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);

/* IO feeds */
AdafruitIO_Feed *feedIncoming = io.feed(FEED_INCOMING);
AdafruitIO_Feed *feedOutgoing = io.feed(FEED_OUTGOING);

Button button = Button(
  PIN_BUTTON,
  TIMEOUT_DEBOUNCE,
  TIMEOUT_PRESS,
  STATE_BUTTON_TRIGGERED);

/* = STATUS LED SETUP = */
StatusLed statusLed = StatusLed(
  PIN_LED_RED,
  PIN_LED_GREEN,
  PIN_LED_BLUE,
  LED_ON_STATE
);

void setup() {
  /* begin serial for debugging */
  Serial.begin(115200);

  /* get pins ready */
  initPins();

  /* init objects */
  statusLed.begin();
  button.begin();
  connectToIo();
}

void initPins() {
  /* init RGB LED pins */
  pinMode(PIN_LED_RED, OUTPUT);
  pinMode(PIN_LED_GREEN, OUTPUT);
  pinMode(PIN_LED_BLUE, OUTPUT);

  /* init button pin */
  pinMode(PIN_BUTTON, INPUT);
}

void connectToIo() {
  Serial.print("Connecting to AdafruitIO...");
  
  io.connect();
  initFeeds();

  boolean isOn = false;

  while(io.status() < AIO_CONNECTED) {
    isOn = !isOn;
    Serial.print(".");

    if (isOn){
      statusLed.yellow();
    }

    if (!isOn) {
      statusLed.green();
    }

    delay(100);
  }

  Serial.println(io.statusText());
  statusLed.blockingFlash(
    false,
    true,
    false,
    6,
    100
  );
}

void initFeeds() {
  feedIncoming->onMessage(handleIncomingMessage);
}

void handleIncomingMessage(AdafruitIO_Data *data) {
  Serial.print("received <- ");
  Serial.println(data->value());

  /* flash purple */
  statusLed.blockingFlash(
    true,
    false,
    true,
    6,
    100
  );
}

void loop() {
  if (button.isPressed()) {
    Serial.println("Pressed!");
    feedOutgoing->save(1);
    /* flash blue */
    statusLed.blockingFlash(
    false,
    false,
    true,
    6,
    100
  );
  }

  /* call run methods on each loop */
  statusLed.run();
  io.run();
}
