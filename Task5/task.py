print("Введите размеры матрицы: ")
h, w = map(int, input().split())

matrix = []
print("Введите матрицу: ")
for _ in range(h):
    row = list(map(int, input().split()))
    matrix.append(row)

# поиск границ фигуры
min_row = h
max_row = 0
min_col = w
max_col = 0

# проходим по всем элементам матрицы
for i in range(h):
    for j in range(w):
        if matrix[i][j] == 1:
            # обновляем границы
            if i < min_row:
                min_row = i
            if i > max_row:
                max_row = i
            if j < min_col:
                min_col = j
            if j > max_col:
                max_col = j

print("Результат: ")
print(f"{min_row} {min_col} {max_row} {max_col}")