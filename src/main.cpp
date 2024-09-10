#include <Arduino.h>
#include <FastLED.h>
#include <WiFi.h>
#include <WebServer.h>
#include <Update.h>

#define POWER_SENSOR_PIN 4
#define POWER_LED_PIN 2
#define NUM_LEDS 1

#define LED_TYPE WS2812B
#define COLOR_ORDER GRB

CRGB leds[NUM_LEDS];
CRGB colors[] = {CRGB::Red, CRGB::Green};

// Задайте имя и пароль вашей Wi-Fi сети
const char *ssid = "your_SSID";         // Замените на имя вашей Wi-Fi сети
const char *password = "your_PASSWORD"; // Замените на пароль вашей Wi-Fi сети

WebServer server(80);

void handleUpdate()
{
  HTTPUpload &upload = server.upload();
  if (upload.status == UPLOAD_FILE_START)
  {
    String filename = upload.filename;
    if (!Update.begin())
    {
      Update.printError(Serial);
    }
  }
  else if (upload.status == UPLOAD_FILE_WRITE)
  {
    if (Update.write(upload.buf, upload.currentSize) != upload.currentSize)
    {
      Update.printError(Serial);
    }
  }
  else if (upload.status == UPLOAD_FILE_END)
  {
    if (Update.end(true))
    {
      Serial.println("Update successful");
    }
    else
    {
      Update.printError(Serial);
    }
  }
}

void initWifi()
{
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to WiFi");

  server.on("/update", HTTP_POST, []()
            { server.send(200, "text/plain", "Update done!"); }, handleUpdate);

  server.begin();
  Serial.println("HTTP server started");
}

void initButton()
{
  // Настройка пинов
  pinMode(POWER_SENSOR_PIN, INPUT); // Пин сенсора как вход
  FastLED.addLeds<LED_TYPE, POWER_LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);

  // Изначально все светодиоды выключены (черный цвет)
  FastLED.clear();
  FastLED.show();
}

void setup()
{

  initWifi();
}

void loop()
{
  server.handleClient();
  // put your main code here, to run repeatedly:
}
