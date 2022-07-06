#include <Servo.h>

//объект управления сервомотором 
Servo servo;
 
void setup() {
    //характеристики сервомотора находим в интернете
    //https://servodatabase.com/servo/towerpro/sg90
    servo.attach(D1, 500, 2400);
    servo.write(0);
    delay(5000);
}
 
void loop() {
    //устанавливаем градусы. от 0 до 180
    servo.write(0);
    delay(3000);
    servo.write(90);
    delay(3000);
    servo.write(180);
    delay(3000);
}
