//подключаем библиотеку https://github.com/FastLED/FastLED
#include "FastLED.h"

//управляющий пин светодиодного бруска neopixel
const byte NEOPIXEL_PIN = D3;
//кол-во светодиодов
const byte NUM_LEDS = 8;
//пин + пьезодинамика
const byte BUZZER_PIN = D2;
//кол-во нот в мелодии
const byte COUNT_NOTES = 39;

//объект neopixel
CRGB leds[NUM_LEDS];

//частоты нот
int tones[COUNT_NOTES] = {
  392, 392, 392, 311, 466, 392, 311, 466, 392,
  587, 587, 587, 622, 466, 369, 311, 466, 392,
  784, 392, 392, 784, 739, 698, 659, 622, 659,
  415, 554, 523, 493, 466, 440, 466,
  311, 369, 311, 466, 392
};

// длительности нот
int durations[COUNT_NOTES] = {
  350, 350, 350, 250, 100, 350, 250, 100, 700,
  350, 350, 350, 250, 100, 350, 250, 100, 700,
  350, 250, 100, 350, 250, 100, 100, 100, 450,
  150, 350, 250, 100, 100, 100, 450,
  150, 350, 250, 100, 750
};

void setup() {
  //пин на выход
  pinMode(BUZZER_PIN, OUTPUT); 
  delay(1000);
  //инициализируем neopixel
  FastLED.addLeds<NEOPIXEL, NEOPIXEL_PIN>(leds, NUM_LEDS);

}

void loop() {
  //для каждой ноты
  for (int i = 0; i <= COUNT_NOTES; i++) {
    //случайным образом задаем цвета в формате RGB (красный, зеленый, синий, 0-255)
    leds[0] = CRGB(random(0, 255), 0, 0);
    leds[1] = CRGB(0, random(0, 255), 0);
    leds[2] = CRGB(0, 0, random(0, 255));
    leds[3] = CRGB(random(0, 255), 0, 0);
    leds[4] = CRGB(0, random(0, 255), 0);
    leds[5] = CRGB(0, 0, random(0, 255));
    leds[6] = CRGB(random(0, 255), random(0, 255), random(0, 255));
    leds[7] = CRGB(random(0, 255), random(0, 255), random(0, 255));
    FastLED.show();
    //шим сигнал с заданной частотой и длительностью
    tone(BUZZER_PIN, tones[i], durations[i] * 2);
    //ждем длительность
    delay(durations[i] * 2);
    //отключаем ноту
    noTone(BUZZER_PIN);
  }
}
