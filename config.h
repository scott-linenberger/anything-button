#ifndef ANYTHING_CONFIG_H
#define ANYTHING_CONFIG_H

/* = WIFI SETUP = */
#define IO_USERNAME "scottlinenberger"
#define IO_KEY "3058994edee143b2a7712f02881567a6"
#define WIFI_SSID "fortiguest"
#define WIFI_PASS "3levatecultur3"

/* feeds */
/* OUT feed is where IOT messages are published */
#define FEED_OUTGOING "anything-button.anything-button-1-out"

/* IN feed is subscribed to so incoming messages 
 * can be received.*/
#define FEED_INCOMING "anything-button.anything-button-1-in"

/* pin declarations */
/* Which setting, HIGH or LOW depending on your RGB led */
/* if writing HIGH to the RGB LED pins turns the LED on, set this to HIGH */
/* if writing LOW to the RGB LED pins turns the LED on, set this to LOW */
#define LED_ON_STATE LOW

/* RGB Led pins */
#define PIN_LED_GREEN 12
#define PIN_LED_BLUE 13
#define PIN_LED_RED 14

#define PIN_BUTTON 4

#endif
