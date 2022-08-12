//wifi сеть
#define WIFI_SSID "ssid"
#define WIFI_PASS "pass"
//Api токен, полученные присоздании бота
#define BOT_TOKEN "API_TOKEN"
//светодиод подключен к D1
#define LED D1

//Библиотека FastLed - уснавливаем как обычно через менеджер библиотек
#include <FastBot.h>
FastBot bot(BOT_TOKEN);

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  //поключение к wifi для красоты вынесем в отдельную функцию
  connectWiFi();
  //инициализируем бота - привязываем обработчик сообщений
  bot.attach(newMsg);
}

// обработчик сообщений
void newMsg(FB_msg& msg) {
  Serial.println(msg.toString());
  //в зависимости от сообщения, включаем или выключаем светодиод
  //и отвечаем отправителю
  if (msg.text == "/on") {
    digitalWrite(LED, HIGH);
    bot.replyMessage("Включено!", msg.messageID, msg.chatID);
  }
  else if (msg.text == "/off") {
    digitalWrite(LED, LOW);
    bot.replyMessage("Выключено!", msg.messageID, msg.chatID);
  }
  //на неизвестное сообщение отвечаем приветсивием
  else {
    bot.replyMessage("Hello! Команды /on /off", msg.messageID, msg.chatID);
  }
}

void loop() {
  //для работы бота
  bot.tick();
}

void connectWiFi() {
  delay(2000);
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    if (millis() > 15000) ESP.restart();
  }
  Serial.println("Connected");
}
