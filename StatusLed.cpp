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

  /* write the values */
}

void StatusLed::setModeFlashing(
  boolean _stateRed,
  boolean _stateGreen,
  boolean _stateBlue,
  uint16_t _timeout
) {
  /* assign vars */
  stateRed = _stateRed;
  stateGreen = _stateGreen;
  stateBlue = _stateBlue;
  timeoutFlash = _timeout;

  mode = 2;
}

void StatusLed::off() {
  digitalWrite(pinRed, offState);
  digitalWrite(pinGreen, offState);
  digitalWrite(pinBlue, offState);
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

void StatusLed::flashRed(uint16_t _timeoutFlash) {
  /* set the timeout */
  timeoutFlash = _timeoutFlash;

}

void StatusLed::flashGreen(uint16_t _timeoutFlash) {

}

void StatusLed::flashBlue(uint16_t _timeoutFlash) {

}