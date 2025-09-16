print("Введите количество пар: ")
n = int(input().strip())
results = []
for _ in range(n):
    print("Введите данные: ")
    data = list(map(int, input().split()))
    a, b, x, y = data
    pairs_B1 = min(b, x)
    rem_x = x - pairs_B1
    pairs_A = min(a, rem_x + y)
    total = pairs_B1 + pairs_A
    results.append(str(total))

print("Результат: ")
print(" ".join(results))