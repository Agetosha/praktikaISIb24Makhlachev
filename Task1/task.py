import random

def find_min_path(mountain, sum):
    cur_pos_j = 0 #текущая позиция по j (горизонтали)
    print("Кратчайший путь:", mountain[0][0], end=' ')

    for i in range(1, n):
        for j in range(cur_pos_j, cur_pos_j + 1):
            if mountain[i][j] > mountain[i][j + 1]:
                cur_pos_j = j + 1
                sum += mountain[i][j + 1]
            else:
                cur_pos_j = j
                sum += mountain[i][j]
            print(mountain[i][cur_pos_j], end=' ') 

    print()
    return sum

n = int(input("Введите количество уровней горы: "))
mountain = []

print("Сгенерированная гора (числа от 10 до 100):")
for i in range(n): #генерируем гору
    mountain.append([])
    for j in range(i + 1):
        mountain[i].append(random.randint(10, 100))
        num = mountain[i][j] #вектор из векторов
        print(num, end=' ')
    print()

sum = mountain[0][0]

print("Минимальное время спуска (сумма):", find_min_path(mountain, sum))