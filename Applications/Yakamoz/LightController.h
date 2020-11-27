
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

int LigthControllerInit(void);
int LigthControllerTest(void);
void LigthControllerDeInit(void);

// toggle led
// setColor
// set brightness

#if __has_feature(nullability)
#pragma clang assume_nonnull end
#endif

#ifdef __cplusplus
}
#endif

#endif  //LC_H