//подключаем библиотеки для работы с сетью
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
//для работы с oled дисплеем, Установить библиотеку: Инструменты -> Управлять библиотеками -> ssd1306 ThingPulse
/**
 * https://github.com/ThingPulse/esp8266-oled-ssd1306
 */
#include <Wire.h>
#include "SSD1306.h"

//html код формы, PROGMEM - храним длинную строку в постоянной памяти, а не оперативной, т.к размер оперативной памяти меньше
//R"=====( )=====" - границы литерала
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<body>
<h3> HTML Form ESP8266</h3>
<form action="/set_text">
  Text:
  <input type="text" name="text" value="Hello">
  <input type="submit" value="Send">
</form> 
</body>
</html>
)=====";

// Данные, соответствующие вашей wifi сети:
const char* ssid = "ssid";
const char* password = "passord";

//экземпляр веб-сервера на 80 порту
ESP8266WebServer server(80);
//экземпляр дисплея на пинах D2, D1
SSD1306  display(0x3C, D2, D1);

//функция обработки отправленных данных
void handleForm() {
  //получаем текст из отправленной формы
  String text = server.arg("text");
  //Пишем в последовательный порт для наглядности
  Serial.println(text);
  //пишем текст на дисплее в верхнем левом углу
  display.clear();
  display.drawString(0, 0, text);
  display.display();
  //ссылка на главную страницу
  String s = "<a href='/'> Go Back </a>";
  server.send(200, "text/html", s);
}

void setup(void) {
  //инициализируем дисплей
  display.init();
  //Большой шрифт
  display.setFont(ArialMT_Plain_24);
  display.flipScreenVertically();
  display.drawString(0, 0, "Text here");
  display.display();
  //Инициализируем последовательный порт для отладки программы. Arduino -> Инструменты -> Монитор порта
  Serial.begin(115200);
  //Подключаемся к wifi
  WiFi.begin(ssid, password);
  Serial.println("");
  //ждем соединения:
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");  //  "Подключились к "
  Serial.println(ssid);
  Serial.print("IP address: ");  //  "IP-адрес: "
  Serial.println(WiFi.localIP() );
  //ip адрес смотрим в Мониторе порта. В браузере набираем Ip адрес

  //отправляем веб страницу на корневой запрос
  server.on("/", []() {
    server.send(200, "text/html", MAIN_page);
  });
  //обрабока запроса на отправку формы
  server.on("/set_text", handleForm);
  server.begin();
  Serial.println("HTTP server started");
}

void loop(void) {
  //для работы вебсервера
  server.handleClient();
}
