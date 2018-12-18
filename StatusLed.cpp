#include "StatusLed.h"

StatusLed::StatusLed(
  uint8_t _pinRed,
  uint8_t _pinGreen,
  uint8_t _pinBlue,
  boolean _onState
) {
  /* assign vars */
  pinRed = _pinRed;
  pinGreen = _pinGreen;
  pinBlue = _pinBlue;
  onState = _onState;

  /* init off state */
  offState = !onState;
}

void StatusLed::begin() {
  /* init the status LED to off */
  off();
}

void StatusLed::run() {
  /* excecute code for the current mode */
  switch(mode) {
    /* off */
    case 0:
      off();
      break;

    /* set to solid color */
    case 1:
      /* nothing to do */
      break;

    /* set to flashing color(s) */
    case 2:
      updateFlashingState();
      break;

    /* default to off if mode unknown */
    default:
      off();
      break;
  }
}

void StatusLed::setModeSolidColor() {
  mode = 1;
}

void StatusLed::updateFlashingState() {
  /* check if it's time to swtich between on/off */
  if (millis() - timeLastFlashed < timeoutFlash) {
    /* timeout hasn't expired yet */
    return;
  }

  /* timeout has expired */
  /* toggle the flashing state */
  stateFlashing = !stateFlashing;

  /* turn all colors off */
  digitalWrite(pinRed, offState);
  digitalWrite(pinGreen, offState);
  digitalWrite(pinBlue, offState);

  /* write the on/off flashing state to pins */
  if (flashingRed) {
    digitalWrite(pinRed, stateFlashing);
  }

  if (flashingGreen) {
    digitalWrite(pinGreen, stateFlashing);
  }

  if (flashingBlue) {
    digitalWrite(pinBlue, stateFlashing);
  }

  /* update the timeLastFlashed timestamp */
  timeLastFlashed = millis();
}

void StatusLed::setModeFlashing(
  boolean _flashingRed,
  boolean _flashingGreen,
  boolean _flashingBlue,
  uint16_t _timeout
) {
  /* assign vars */
  timeoutFlash = _timeout;
  flashingRed = _flashingRed;
  flashingGreen = _flashingGreen;
  flashingBlue = _flashingBlue;

  /* set the mode to flashing */
  mode = 2;
}

void StatusLed::off() {
  digitalWrite(pinRed, offState);
  digitalWrite(pinGreen, offState);
  digitalWrite(pinBlue, offState);

  /* set the mode to off */
  mode = 0;
}

void StatusLed::red() {
  off();
  /* set the mode to solid color */
  setModeSolidColor();
  digitalWrite(pinRed, onState);
}

void StatusLed::green() {
  off();
  /* set the mode to solid color */
  setModeSolidColor();
  digitalWrite(pinGreen, onState);
}

void StatusLed::blue() {
  off();
  /* set the mode to solid color */
  setModeSolidColor();
  digitalWrite(pinBlue, onState);
}

void StatusLed::purple() {
  off();
  /* set the mode to solid color */
  setModeSolidColor();
  digitalWrite(pinRed, onState);
  digitalWrite(pinBlue, onState);
}

void StatusLed::yellow() {
  off();
  /* set the mode to solid color */
  setModeSolidColor();
  digitalWrite(pinRed, onState);
  digitalWrite(pinGreen, onState);
}

void StatusLed::white() {
  off();

  /* set the mode to solid color */
  setModeSolidColor();
  digitalWrite(pinRed, onState);
  digitalWrite(pinGreen, onState);
  digitalWrite(pinBlue, onState);
}

void StatusLed::flashRed(uint16_t _timeoutFlash) {
  setModeFlashing(
    true,
    false,
    false,
    _timeoutFlash
  );
}

void StatusLed::flashGreen(uint16_t _timeoutFlash) {
  setModeFlashing(
    false,
    true,
    false,
    _timeoutFlash
  );
}

void StatusLed::flashBlue(uint16_t _timeoutFlash) {
  setModeFlashing(
    false,
    false,
    true,
    _timeoutFlash
  );
}

void StatusLed::flashPurple(uint16_t _timeoutFlash) {
  setModeFlashing(
    true,
    false,
    true,
    _timeoutFlash
  );
}

void StatusLed::flashYellow(uint16_t _timeoutFlash) {
  setModeFlashing(
    true,
    true,
    false,
    _timeoutFlash
  );
}

void StatusLed::flashAqua(uint16_t _timeoutFlash) {
  setModeFlashing(
    false,
    true,
    true,
    _timeoutFlash
  );
}

void StatusLed::flashWhite(uint16_t _timeoutFlash) {
  setModeFlashing(
    true,
    true,
    true,
    _timeoutFlash
  );
}

void StatusLed::blockingFlash(
  boolean red,
  boolean green,
  boolean blue,
  uint8_t timesToFlash,
  uint16_t delayBetweenFlashes
) {

  /* turn the LED off */
  off();

  /* on/off flag */
  boolean isOn = false;

  /* begin flashing */
  for (uint8_t i = 0; i < timesToFlash; i++) {
    /* toggle the on/off flag */
    isOn = !isOn;

    /* write to the pins */
    if (red) {
      digitalWrite(pinRed, isOn);
    }

    if (green) {
      digitalWrite(pinGreen, isOn);
    }

    if (blue) {
      digitalWrite(pinBlue, isOn);
    }

    /* wait */
    delay(delayBetweenFlashes);
  }

  off();
}