#include <Adafruit_NeoPixel.h>

#define DATA_PIN 6
#define NUM_LEDS 64

Adafruit_NeoPixel matrix(NUM_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);

// вычисляем индекс светодиода по координатам
int indexFromXY(int col, int row)
{
    if (row % 2 == 0)
    {
        return row * 8 + col;
    }
    else
    {
        return row * 8 + (7 - col);
    }
}

void setup()
{
    matrix.begin();
    matrix.clear();
    matrix.show();
}

void loop()
{
    drawArrow();
    drawCross();
    rainbowFill();
}

// отображение стрелки
void drawArrow()
{
    byte arrow[8][8] = {
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 1, 1, 1, 1, 0, 0},
        {0, 1, 0, 1, 1, 0, 1, 0},
        {1, 0, 0, 1, 1, 0, 0, 1},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0}};

    for (int rep = 0; rep < 2; rep++)
    {
        matrix.clear();
        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                if (arrow[y][x])
                {
                    matrix.setPixelColor(indexFromXY(x, y), matrix.Color(0, 200, 255));
                }
            }
        }
        matrix.show();
        delay(600);
        matrix.clear();
        matrix.show();
        delay(300);
    }
}

// отображение крестика
void drawCross()
{
    byte cross[8][8] = {
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 0, 0}};

    for (int rep = 0; rep < 2; rep++)
    {
        matrix.clear();
        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                if (cross[y][x])
                {
                    matrix.setPixelColor(indexFromXY(x, y), matrix.Color(255, 50, 50));
                }
            }
        }
        matrix.show();
        delay(600);
        matrix.clear();
        matrix.show();
        delay(300);
    }
}

// эффект последовательного заполнения цветами
void rainbowFill()
{
    int pal[3][3] = {
        {255, 0, 0},
        {0, 255, 0},
        {0, 0, 255}};

    for (int c = 0; c < 3; c++)
    {
        for (int i = 0; i < NUM_LEDS; i++)
        {
            matrix.setPixelColor(i, matrix.Color(pal[c][0], pal[c][1], pal[c][2]));
            matrix.show();
            delay(25);
        }
        delay(350);
        matrix.clear();
        matrix.show();
        delay(250);
    }
}
