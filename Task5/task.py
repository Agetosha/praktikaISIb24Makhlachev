print("Введите количество строк(h) и количество столбцов(w): ")
h, w = map(int, input().split())
matrix = [list(map(int, input().split())) for _ in range(h)]

print("Введите матрицу: ")
min_r, max_r = h, -1
min_c, max_c = w, -1

for i in range(h):
    for j in range(min(w, len(matrix[i]))):
        if matrix[i][j] == 1:
            if i < min_r: min_r = i
            if i > max_r: max_r = i
            if j < min_c: min_c = j
            if j > max_c: max_c = j

# чтобы границы не задевали фигуру:
top = min_r + 1
left = min_c - 1
bottom = max_r + 4
right = max_c + 1

print("Результат: ")
print(top, left, bottom, right)
