print("Введите количество улиц(n) и запросов(k): ")
n, k = map(int, input().split()) #применяет int к каждому введенному элементу списка, разделенного пробелами
streets = [0] * (n + 1)
queries = [] #все запросы

print("Введите запросы: ")
for _ in range(k):
    q = list(map(int, input().split()))
    queries.append(q)

answers = []

for q in queries:
    if q[0] == 1:  
        # добавить снег на улицу i
        _, i, x = q #распаковка списка _ значит что первая переменная не используется
        streets[i] += x
    else:  
        # запрос суммы от u до r
        _, u, r = q
        total = sum(streets[u:r+1])
        answers.append(total)

print("Ответы на запросы: ")
for i in answers:
    print(i)
