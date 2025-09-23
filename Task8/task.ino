#include <Adafruit_NeoPixel.h>
#define PIN 6
#define LED_COUNT 64

Adafruit_NeoPixel leds(LED_COUNT, PIN, NEO_GRB + NEO_KHZ800);
int getIndex(int x, int y)
{
    return (y % 2 == 0) ? (y * 8 + x) : (y * 8 + (7 - x));
}

void setup()
{
    leds.begin();
}

void loop()
{
    smiley();
    heart();
    fillEffect();
}

void smiley()
{
    byte smile[8][8] = {
        {0, 0, 1, 1, 1, 1, 0, 0},
        {0, 1, 0, 0, 0, 0, 1, 0},
        {1, 0, 1, 0, 0, 1, 0, 1},
        {1, 0, 0, 0, 0, 0, 0, 1},
        {1, 0, 1, 0, 0, 1, 0, 1},
        {1, 0, 0, 1, 1, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 1, 1, 0, 0}};

    for (int i = 0; i < 3; i++)
    {
        leds.clear();
        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                if (smile[y][x])
                {
                    leds.setPixelColor(getIndex(x, y), leds.Color(255, 255, 0));
                }
            }
        }
        leds.show();
        delay(500);
        leds.clear();
        leds.show();
        delay(300);
    }
}

void heart()
{
    byte heart[8][8] = {
        {0, 1, 1, 0, 0, 1, 1, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 1, 1, 1, 1, 1, 1, 0},
        {0, 0, 1, 1, 1, 1, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0}};

    for (int i = 0; i < 3; i++)
    {
        leds.clear();
        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                if (heart[y][x])
                {
                    leds.setPixelColor(getIndex(x, y), leds.Color(255, 0, 0));
                }
            }
        }
        leds.show();
        delay(500);
        leds.clear();
        leds.show();
        delay(300);
    }
}

void fillEffect()
{
    int colors[3][3] = {
        {255, 0, 0},
        {0, 255, 0},
        {0, 0, 255}};

    for (int c = 0; c < 3; c++)
    {
        for (int i = 0; i < 64; i++)
        {
            leds.setPixelColor(i, leds.Color(colors[c][0], colors[c][1], colors[c][2]));
            leds.show();
            delay(30);
        }
        delay(300);
        leds.clear();
        leds.show();
        delay(300);
    }
}