#include <pigpio.h>
#include "LightBulb.h"


#define HIGH 1
#define LOW 0

#define TEST_PIN 17

HAPError BulbOneInit(void);
HAPError BulbOneHandleToggle(void);
HAPError BulbOneDeInit(void);
HAPError BulbOneHandleSetBrigthness(int32_t brigthness);
HAPError BulbOneHandleSetColor(int32_t color);
/* Bulb one Handlers */
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
LightBulb bulbOne = {
  .on = false,
  .brightness = 100,
  .color = 100,
  .colorConstraints = {
    .minimumValue = 50,
    .maximumValue = 400,
    .stepValue = 1,
  },
  .brightnessConstraints = {
    .minimumValue = 5,
    .maximumValue = 100,
    .stepValue = 5,
  },
  .init = BulbOneInit,
  .deInit = BulbOneDeInit,
  .toggle = BulbOneHandleToggle,
  .setBrightness = BulbOneHandleSetBrigthness,
  .setColor = BulbOneHandleSetColor,
};


HAPError BulbOneInit(void) {
  int32_t gpioInit;
  if ((gpioInit = gpioSetMode(TEST_PIN, PI_OUTPUT)) == PI_BAD_GPIO || gpioInit == PI_BAD_MODE) {
    return kHAPError_OutOfResources;
  }
  return kHAPError_None;
}

HAPError BulbOneHandleToggle(void) {
  int32_t w;

  bulbOne.on = !bulbOne.on;
  if ((w = gpioWrite(TEST_PIN, bulbOne.on) == PI_BAD_GPIO)
       || w == PI_BAD_LEVEL) {
    return kHAPError_OutOfResources;
  }
  return kHAPError_None;
}

HAPError BulbOneDeInit(void) {
  return kHAPError_None;
}

HAPError BulbOneHandleSetBrigthness(int32_t brigthness) {
  bulbOne.brightness = brigthness;
  return kHAPError_None;
}

HAPError BulbOneHandleSetColor(int32_t color) {
  bulbOne.color = color;
  return kHAPError_None;
}
