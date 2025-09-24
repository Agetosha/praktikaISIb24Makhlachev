#include <Adafruit_NeoPixel.h>

#define DATA_PIN 6
#define NUM_LEDS 64
// создание объекта для управления светодиодной матрицей
Adafruit_NeoPixel matrix(NUM_LEDS, DATA_PIN, NEO_GRB + NEO_KHZ800);
// NUM_LEDS - количество светодиодов (64 для матрицы 8x8)
// DATA_PIN - пин Arduino, к которому подключена матрица (пин 6)
// NEO_GRB - порядок цветов: Green, Red, Blue
// NEO_KHZ800 - частота передачи данных (800 kHz для NeoPixel)

// вычисляем индекс светодиода по координатам
int indexFromXY(int col, int row)
{
    if (row % 2 == 0)
    {                         // если строка четная
        return row * 8 + col; // светодиоды идут слева направо
    }
    else
    {                               // если строка нечетная
        return row * 8 + (7 - col); // светодиоды идут зигзагом
    }
}

void setup()
{
    matrix.begin(); // инициализация библиотеки
    matrix.clear(); // очистка матрицы (все светодиоды выключены)
    matrix.show();  // применение изменений (отправка данных на матрицу)
}

void loop() // выполняется бесконечно после setup()
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
    {                   // повторить 2 раза
        matrix.clear(); // очистить матрицу

        // проход по всем пикселям матрицы 8x8
        for (int y = 0; y < 8; y++)
        {
            for (int x = 0; x < 8; x++)
            {
                if (arrow[y][x])
                { // если в матрице стрелки 1
                    // включить светодиод с цветом (0,200,255) - голубой
                    matrix.setPixelColor(indexFromXY(x, y), matrix.Color(0, 200, 255));
                }
            }
        }

        matrix.show(); // показать стрелку
        delay(600);    // ждать 600 мс

        matrix.clear(); // очистить матрицу
        matrix.show();  // применить очистку
        delay(300);     // ждать 300 мс (мигание)
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
// как работает отрисовка:
//     создается битовая карта (массив 8x8), где 1 - светить, 0 - не светить
//     двойной цикл проходит по всем координатам матрицы
//     проверка условия if (arrow[y][x]) - если элемент равен 1
//     установка цвета для конкретного светодиода через indexFromXY()
//     show() отправляет все изменения на матрицу
//     мигание создается чередованием показа и очистки
