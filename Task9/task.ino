#define LDR_PIN A0 // фоторезистор
#define LED_GREEN 5
#define LED_RED 12

const int lightBorder = 512;          // граница срабатывания
const unsigned long openDelay = 3000; // время открытой двери

void setup()
{
    pinMode(LED_GREEN, OUTPUT);
    pinMode(LED_RED, OUTPUT);
    Serial.begin(9600);

    // стартовое состояние: дверь закрыта
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
    Serial.println("Дверь закрыта");
}

void loop()
{
    int lightLevel = analogRead(LDR_PIN);

    if (lightLevel > lightBorder)
    {
        openDoor();
    }
}

void openDoor()
{
    bool doorAlreadyOpen = (digitalRead(LED_GREEN) == HIGH);

    digitalWrite(LED_RED, LOW);
    digitalWrite(LED_GREEN, HIGH);

    if (!doorAlreadyOpen)
    {
        Serial.println("Дверь открывается...");
    }

    delay(openDelay);

    int lightCheck = analogRead(LDR_PIN);
    if (lightCheck <= lightBorder)
    {
        digitalWrite(LED_GREEN, LOW);
        digitalWrite(LED_RED, HIGH);
        Serial.println("Дверь закрывается");
    }
}
