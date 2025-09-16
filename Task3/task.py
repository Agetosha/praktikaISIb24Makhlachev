n, k = map(int, input().split())
streets = [0] * (n + 1) # массив для улиц
queries = [] #все запросы

for _ in range(k):
    q = list(map(int, input().split()))
    queries.append(q)

answers = []

for q in queries:
    if q[0] == 1:  
        # добавить снег на улицу i
        _, i, x = q
        streets[i] += x
    else:  
        # запрос суммы от u до r
        _, u, r = q
        total = sum(streets[u:r+1])
        answers.append(total)

for i in answers:
    print(i)
