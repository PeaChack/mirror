#include <Arduino.h>
#include <FastLED.h>

#define POWER_SENSOR_PIN 4
#define POWER_LED_PIN    2
#define NUM_LEDS         1

#define LED_TYPE         WS2812B
#define COLOR_ORDER      GRB

CRGB leds[NUM_LEDS];
CRGB colors[] = {CRGB::Red, CRGB::Green};
// put function declarations here:
int myFunction(int, int);

void setup() {
    // Настройка пинов
  pinMode(POWER_SENSOR_PIN, INPUT);  // Пин сенсора как вход
  pinMode(POWER_LED_PIN, OUTPUT);    // Пин светодиода как выход
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}