#define PHOTO_SENSOR A0

#define GREEN_LED 5
#define RED_LED 12

const int threshold = 512;
const unsigned long doorOpenTime = 3000;

void setup()
{
    pinMode(GREEN_LED, OUTPUT);
    pinMode(RED_LED, OUTPUT);
    Serial.begin(9600);

    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    Serial.println("Двери закрыты");
}

void loop()
{
    int sensorValue = analogRead(PHOTO_SENSOR);
    bool isDoorOpen = false;
    if (digitalRead(GREEN_LED) == HIGH)
    {
        isDoorOpen = true;
    }

    if (sensorValue > threshold)
    {
        digitalWrite(RED_LED, LOW);
        digitalWrite(GREEN_LED, HIGH);
        if (!isDoorOpen)
        {
            Serial.println("Двери открываются!");
        }

        delay(doorOpenTime);

        sensorValue = analogRead(PHOTO_SENSOR);
        if (sensorValue <= threshold)
        {
            digitalWrite(GREEN_LED, LOW);
            digitalWrite(RED_LED, HIGH);
            Serial.println("Двери закрываются");
        }
    }
}