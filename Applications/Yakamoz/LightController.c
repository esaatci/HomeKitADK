#include "LightController.h"
#include "LightBulb.h"

#define TEST_PIN 17
#define HIGH 1
#define LOW 0
#define NUM_BULBS 1
#define bulb(x) controller.bulbs[(x)]

extern LightBulb bulbOne;

typedef struct {
  LightBulb *bulbs[NUM_BULBS];
} LightController;

static LightController controller = {
  .bulbs = { &bulbOne }
};


HAPError LigthControllerInit(void) {
  int i;
  HAPError err;

  if (gpioInitialise() < 0) {
    return kHAPError_OutOfResources;
  }
  for (i = 0; i < NUM_BULBS; i++) {
    err = bulb(i)->init();
    if (err) {
      return err;
    }
  }
  return kHAPError_None;
}

HAPError LightControllerToggle(int32_t ledNum) {
  if (ledNum >= NUM_BULBS) {
    return kHAPError_InvalidData;
  }
  return bulb(ledNum)->toggle();
}

HAPError LigthControllerDeInit(void) {

  int i;
  HAPError err;
  for (i = 0; i < NUM_BULBS; i++) {
    err = bulb(i)->deInit();
    if (err) {
      return err;
    }
  }
  gpioTerminate();
  return kHAPError_None;
}

HAPError LightControllerSetColor(int32_t ledNum, int32_t color) {
  if (ledNum >= NUM_BULBS) {
    return kHAPError_InvalidData;
  }
  return bulb(ledNum)->setColor(color);
}

HAPError LightControllerSetBrightness(int32_t ledNum, int32_t brightness) {
  if (ledNum >= NUM_BULBS) {
    return kHAPError_InvalidData;
  }
  return bulb(ledNum)->setBrightness(brightness);
}
