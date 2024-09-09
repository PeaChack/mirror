#include <Arduino.h>
#include <FastLED.h>
#include <WiFi.h>

#define POWER_SENSOR_PIN 4
#define POWER_LED_PIN    2
#define NUM_LEDS         1

#define LED_TYPE         WS2812B
#define COLOR_ORDER      GRB

// Задайте имя и пароль вашей Wi-Fi сети
const char* ssid = "your_SSID";      // Замените на имя вашей Wi-Fi сети
const char* password = "your_PASSWORD"; // Замените на пароль вашей Wi-Fi сети

CRGB leds[NUM_LEDS];
CRGB colors[] = {CRGB::Red, CRGB::Green};
// put function declarations here:
int myFunction(int, int);

void setup() {
  // Настройка пинов
  pinMode(POWER_SENSOR_PIN, INPUT);  // Пин сенсора как вход
  FastLED.addLeds<LED_TYPE, POWER_LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // Изначально все светодиоды выключены (черный цвет)
  FastLED.clear();
  FastLED.show();
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}