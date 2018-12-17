#ifndef STATUSLED_H
#define STATUSLED_H
#include <Arduino.h>

class StatusLed {
  private:
  uint8_t mode = 0;

  uint8_t pinRed;
  uint8_t pinGreen;
  uint8_t pinBlue;
  boolean onState;
  boolean offState;

  /* flashing state vars */
  boolean stateRed;
  boolean stateGreen;
  boolean stateBlue;

  uint16_t timeoutFlash;
  boolean stateFlashing = true;
  unsigned long timeLastFlashed = 0;

  /* private methods */
  void setModeSolidColor();
  void updateFlashingState();
  void setModeFlashing(
    boolean _stateRed,
    boolean _stateGreen,
    boolean _stateBlue,
    uint16_t _timeout
  );

  public:
  StatusLed(
    uint8_t _pinRed,
    uint8_t _pinGreen,
    uint8_t _pinBlue,
    boolean _onState
  );
  void begin();
  void run();
  void off();
  void red();
  void green();
  void blue();
  void flashRed(uint16_t _timeoutFlash);
  void flashGreen(uint16_t _timeoutFlash);
  void flashBlue(uint16_t _timeoutFlash);
};

#endif
