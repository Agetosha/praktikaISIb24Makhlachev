#include <Servo.h>

Servo myServo;
int currentAngle = 0;

void setup()
{
    Serial.begin(9600);
    myServo.attach(4);
    myServo.write(currentAngle);
    Serial.println("Введите угол (0-180): ");
}

void loop()
{
    if (Serial.available() > 0)
    {
        int newAngle = Serial.parseInt();

        if (newAngle >= 0 && newAngle <= 180)
        {
            if (newAngle != currentAngle)
            {
                Serial.print("Сервопривод поворачивается на: ");
                Serial.println(newAngle);

                if (newAngle > currentAngle)
                {
                    for (int i = currentAngle; i <= newAngle; i++)
                    {
                        myServo.write(i);
                        delay(15);
                    }
                }
                else
                {
                    for (int i = currentAngle; i >= newAngle; i--)
                    {
                        myServo.write(i);
                        delay(15);
                    }
                }
                currentAngle = newAngle;
            }
        }
        else
        {
            Serial.println("Ошибка! Введите угол от 0 до 180");
        }
    }
}