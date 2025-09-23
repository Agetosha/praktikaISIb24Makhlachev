#include <Servo.h>

Servo servoMotor;
int lastPos = 0;

void setup()
{
    Serial.begin(9600);
    servoMotor.attach(4);
    servoMotor.write(lastPos);
    Serial.println("Введите значение угла от 0 до 180:");
}

void loop()
{
    if (Serial.available())
    {
        int target = Serial.parseInt();

        if (target < 0 || target > 180)
        {
            Serial.println("Некорректный ввод! Диапазон: 0–180");
            return;
        }

        if (target == lastPos)
        {
            Serial.println("Сервопривод уже находится в этой позиции.");
            return;
        }

        Serial.print("Движение к углу: ");
        Serial.println(target);
        int step = 0;
        if (target > lastPos)
        {
            step = 1;
        }
        else
        {
            step = -1;
        }

        for (int pos = lastPos; pos != target + step; pos += step)
        {
            servoMotor.write(pos);
            delay(15);
        }

        lastPos = target;
    }
}
