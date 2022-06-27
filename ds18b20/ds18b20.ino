//библиотеки для работы с ds
#include <OneWire.h>
#include <DallasTemperature.h>

//общение с датчиком по oneWire
OneWire oneWire(D4);

//экземпляр датчика
DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(115200);
  //инициализируем датчик
  sensors.begin();
}

void loop(void)
{
  //запрос на измерение температуры
  sensors.requestTemperatures(); 
  //получаем температуру с первого датчика(можно подключить несколько)
  float tempC = sensors.getTempCByIndex(0);
  //выводим в монитор порта
  Serial.println(tempC);
}
