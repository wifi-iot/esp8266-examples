
## Начало работы

Чтобы начать работать с Wemos D1 (модели mini и R2 полностью совместимы, см наименования пинов на плате), необходимо установить драйвер CH340 и Arduino IDE.  

Найти драйвер можно на официальной странице [https://www.wemos.cc/en/latest/ch340_driver.html](https://www.wemos.cc/en/latest/ch340_driver.html)


Arduino IDE:
[https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
 

Чтобы начать работу в Arduino IDE, нужно  установить поддержку esp8266.  Меню Файл – Настройки, ввести в строку «дополнительные ссылки для менеджера плат»

ссылку [http://arduino.esp8266.com/stable/package_esp8266com_index.json](http://arduino.esp8266.com/stable/package_esp8266com_index.json) и нажать ОК.
 

Затем в Инструменты – Плата – менеджер плат найти esp8266 by ESP8266 Community, установить и закрыть окно.
В меню инструменты – Плата – выбрать Wemos D1 R2 & mini  

Для загрузки программы в микроконтроллер, необходимо подключить его по micro usb, выбрать порт(если не выбран), загрузить нажав стрелку в Arduino IDE.


<br/>

## Примеры проектов на Wemos D1


[Управление светодиодом по нажатию кнопки](button_led)

[Управление яркостью светодиода](pwm_led)

[Управление дисплеем из веб-браузера](ssd1306_webserver) (WI-FI)

[Управление реле по точному времени](relay_ntp) (WI-FI)

[Измерение температуры](ds18b20)

[Цветомузыка](color_music)

[Управление сервомотором](sg90)


[Управление светодиодом из любой точки мира через Telegram (telegram_simple) (WI-FI)
