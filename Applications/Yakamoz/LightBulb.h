#ifndef BULB_H
#define BULB_H

#ifdef __cplusplus
extern "C" {
#endif

#include "HAP.h"

#define HIGH 1
#define LOW 0

#if __has_feature(nullability)
#pragma clang assume_nonnull begin
#endif


typedef struct {
  bool on;

  int32_t brightness;

  int32_t color;

  struct {
    int8_t minimumValue;
    int8_t maximumValue;
    int8_t stepValue;
  } colorConstraints;

  struct {
    int8_t minimumValue;
    int8_t maximumValue;
    int8_t stepValue;
  } brightnessConstraints;

  HAPError (* init)(void);
  HAPError (* deInit)(void);
  HAPError (* toggle)(void);
  HAPError (* setBrightness)(int32_t brigthness);
  HAPError (* setColor)(int32_t color);

} LightBulb;


#if __has_feature(nullability)
#pragma clang assume_nonnull end
#endif

#ifdef __cplusplus
}
#endif

#endif // BULB_H
