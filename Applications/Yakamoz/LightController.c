#include "LightController.h"

#define TEST_PIN 17
#define HIGH 1
#define LOW 0

static int state = LOW;

int LigthControllerInit(void) {
  int gpioInit;

  if (gpioInitialise() < 0) {
    return 1;
  }

  if((gpioInit = gpioSetMode(TEST_PIN, PI_OUTPUT)) == PI_BAD_GPIO || gpioInit == PI_BAD_MODE) {
    return 1;
  }

  return 0;
}

int LigthControllerTest(void) {
  int w;

  state = !state;
  if ((w = gpioWrite(TEST_PIN, state) == PI_BAD_GPIO) || w == PI_BAD_LEVEL) {
    return 1;
  }

  return 0;
}

void LigthControllerDeInit(void) {
  gpioTerminate();
}
