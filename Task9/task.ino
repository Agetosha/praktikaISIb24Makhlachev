const byte PIN_RED = 9;
const byte PIN_GREEN = 5;
const byte SENSOR_PIN = A0;

// параметры для расчёта освещённости
const float FACTOR = 0.7;      // коэффициент для формулы пересчета
const float RESIST_REF = 50.0; // опорное сопротивление для калибровки

// функция пересчёта аналогового входа в люксы
int calcLux(int raw)
{
    // преобразуем сырое значение (0-1023) в напряжение (0-5В)
    float u = (raw / 1023.0) * 5.0;

    // вычисляем сопротивление фоторезистора по формуле делителя напряжения
    float r = 2000.0 * u / (5.0 - u);

    // пересчитываем сопротивление в уровень освещенности в люксах
    float lux = pow((RESIST_REF * 1000.0 * pow(10, FACTOR)) / r, 1.0 / FACTOR);

    return (int)lux;
}

void setup()
{
    // настраиваем пины светодиодов как выходы
    pinMode(PIN_RED, OUTPUT);
    pinMode(PIN_GREEN, OUTPUT);

    // инициализируем последовательный порт для отладки
    Serial.begin(115200);

    // устанавливаем начальное состояние - дверь закрыта
    digitalWrite(PIN_RED, HIGH);  // красный горит - закрыто
    digitalWrite(PIN_GREEN, LOW); // зеленый выключен
}

void loop()
{
    // читаем значение с фоторезистора
    int sensor = analogRead(SENSOR_PIN);
    delay(3000); // ждем 3 секунды между измерениями

    // проверяем — если ярко, открываем дверь
    if (calcLux(sensor) >= 512)
    {
        // открываем дверь - включаем зеленый, выключаем красный
        digitalWrite(PIN_RED, LOW);
        digitalWrite(PIN_GREEN, HIGH);
        Serial.println("Двери открываются");

        // ждем 3 секунды и проверяем снова
        delay(3000);
        sensor = analogRead(SENSOR_PIN);

        // повторная проверка освещенности
        if (calcLux(sensor) < 512)
        {
            // если стало темно - закрываем дверь
            digitalWrite(PIN_RED, HIGH);
            digitalWrite(PIN_GREEN, LOW);
            Serial.println("Двери закрываются");
        }
        delay(3000); // ждем перед следующим циклом
    }
}