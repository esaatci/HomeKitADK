#include "LightController.h"
#include "LightBulb.h"

#define TEST_PIN 17

// static struct {
//   // arr to hold lightBulbs
//   // number of Ligthbulbss
// } LightController;


static int32_t state = LOW;

int32_t LigthControllerInit(void) {
  int32_t gpioInit;
  if (gpioInitialise() < 0) {
    return 1;
  }
  if ((gpioInit = gpioSetMode(TEST_PIN, PI_OUTPUT)) == PI_BAD_GPIO || gpioInit == PI_BAD_MODE) {
    return 1;
  }

  return 0;
}

int32_t LigthControllerTest(void) {
  int32_t w;

  state = !state;
  if ((w = gpioWrite(TEST_PIN, state) == PI_BAD_GPIO) || w == PI_BAD_LEVEL) {
    return 1;
  }

  return 0;
}

void LigthControllerDeInit(void) {
  gpioTerminate();
}
