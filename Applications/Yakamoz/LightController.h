#ifndef LC_H
#define LC_H

#ifdef __cplusplus
extern "C" {
#endif

#include <pigpio.h>
#include "HAP.h"

#if __has_feature(nullability)
#pragma clang assume_nonnull begin
#endif

int32_t LigthControllerInit(void);
int32_t LigthControllerTest(void);
void LigthControllerDeInit(void);

// toggle led
int32_t LightControllerToggle(int32_t ledNum);
// setColor
int32_t LightControllerSetColor(int32_t ledNum, int32_t color);
// set brightness
int32_t LightControllerSetBrightness(int32_t ledNum, int32_t brightness);

#if __has_feature(nullability)
#pragma clang assume_nonnull end
#endif

#ifdef __cplusplus
}
#endif

#endif  //LC_H
