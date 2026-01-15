#include <Arduino.h>
#include "tinyLED.h"

#define TLED_ORDER ORDER_GRB
#define TLED_CHIP LED_WS2812

tinyLED<1> strip; // pin 1 port b (D9)

#define NUM_MATRIXES 4
#define NUM_LEDS 256 * NUM_MATRIXES // 256 leds on each matrix
#define BRIGHTNESS 40

void setup() {
  strip.setBrightness(BRIGHTNESS);
  strip.clear(NUM_LEDS);
}

void loop() {
  for (int i = 0; i <= NUM_LEDS / 3; i++) {
    strip.send(mGreen);
    strip.send(mRed);
    strip.send(mWhite);
  }

  delay(1000);

  for (int i = 0; i <= NUM_LEDS / 3; i++) {
    strip.send(mWhite);
    strip.send(mGreen);
    strip.send(mRed);
  }

  delay(1000);

  for (int i = 0; i <= NUM_LEDS / 3; i++) {
    strip.send(mRed);
    strip.send(mWhite);
    strip.send(mGreen);
  }

  delay(1000);
}