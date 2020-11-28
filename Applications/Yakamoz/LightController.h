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

HAPError LigthControllerInit(void);
HAPError LigthControllerDeInit(void);

// toggle led
HAPError LightControllerToggle(int32_t ledNum);
// setColor
HAPError LightControllerSetColor(int32_t ledNum, int32_t color);
// set brightness
HAPError LightControllerSetBrightness(int32_t ledNum, int32_t brightness);

#if __has_feature(nullability)
#pragma clang assume_nonnull end
#endif

#ifdef __cplusplus
}
#endif

#endif  // LC_H
