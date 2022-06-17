// Устанавливаем через Менеджер библиотек NTP Client by Farbrice Weinberg
// https://github.com/arduino-libraries/NTPClient
#include <NTPClient.h>
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

#define PIN_RELAY D1

//будем включать реле с 12:30 до 12:35
const int startRelayHours = 12;
const int startRelayMinutes = 30;
const int endRelayHours = 12;
const int endRelayMinutes = 35;

const char *ssid     = "ssid";
const char *password = "password";

//ntp сервер по протоколу udp
WiFiUDP ntpUDP;

// По умолчанию используется 'pool.ntp.org' с интервалом обновления времени 60 сек
NTPClient timeClient(ntpUDP);

void setup() {
  //модуль реле управляется сигналом 5в, сигналы esp8266 - 3.3в, режим пина позволяет управлять данным модулем реле в виду особенности его схемы
  pinMode(PIN_RELAY, OUTPUT_OPEN_DRAIN);
  // Переключаем реле - посылаем низкий сигнал
  digitalWrite(PIN_RELAY, HIGH);
  //включаем последовательный порт
  Serial.begin(115200);
  // подключаемся к wifi
  WiFi.begin(ssid, password);
  while ( WiFi.status() != WL_CONNECTED ) {
    delay ( 500 );
    Serial.print ( "." );
  }
  // инициализируем NTPClient, устанавливаем часовой пояс, 3 часа = 10800 сек
  timeClient.setTimeOffset(10800);
  timeClient.begin();
}

void loop() {
 timeClient.update();
  //получаем текущее время с сервера синхронизации время
  int h = timeClient.getHours();
  int m = timeClient.getMinutes();
  //включаем реле в заданный интервал
  if (h >= startRelayHours && m >= startRelayMinutes && h <= endRelayHours && m <= endRelayMinutes)
    digitalWrite(PIN_RELAY, LOW);
  else
    digitalWrite(PIN_RELAY, HIGH);
  Serial.println(timeClient.getFormattedTime());
}
