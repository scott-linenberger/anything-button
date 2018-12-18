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
  boolean flashingRed;
  boolean flashingGreen;
  boolean flashingBlue;

  uint16_t timeoutFlash;
  /* holds the flashing on/off state */
  boolean stateFlashing = true;
  unsigned long timeLastFlashed = 0;

  /* private methods */
  void setModeSolidColor();
  void updateFlashingState();
  void setModeFlashing(
    boolean _flashingRed,
    boolean _flashingGreen,
    boolean _flashingBlue,
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

  /* solid colors */
  void red();
  void green();
  void blue();
  void purple();
  void yellow();
  void aqua();
  void white();

  /* flashing colors */
  void flashRed(uint16_t _timeoutFlash);
  void flashGreen(uint16_t _timeoutFlash);
  void flashBlue(uint16_t _timeoutFlash);
  void flashPurple(uint16_t _timeoutFlash);
  void flashYellow(uint16_t _timeoutFlash);
  void flashAqua(uint16_t _timeoutFlash);
  void flashWhite(uint16_t _timeoutFlash);

  void blockingFlash(
    boolean red,
    boolean green,
    boolean blue,
    uint8_t timesToFlash,
    uint16_t delayBetweenFlashes
  );
};

#endif
