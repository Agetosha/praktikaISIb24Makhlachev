print("Введите количество элементов(n), запросы(k): ")
n, k = map(int, input().split())
print("Введите перестановку: ")
P = list(map(int, input().split()))
print("Введите строку: ")
s = input().strip()

orig = [''] * n
visited = [False] * n

for i in range(n):
    if visited[i]:
        continue
    cycle = []
    cur = i
    while not visited[cur]:
        visited[cur] = True
        cycle.append(cur)
        cur = P[cur] - 1  # перестановка 1-based

    L = len(cycle)
    shift = k % L
    for idx_in_cycle, pos in enumerate(cycle):
        j = cycle[(idx_in_cycle + shift) % L]
        orig[j] = s[pos]

print("Результат: ")
print("".join(orig))
