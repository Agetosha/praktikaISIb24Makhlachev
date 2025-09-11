import random

def dfs(graph, start_node, visited):
    stack = [start_node]  # создаем стек и кладем в него стартовый узел
    
    while stack:  # пока стек не пуст
        node = stack.pop()  # берем последний добавленный узел
        if node not in visited:  # если его еще не посещали
            visited.add(node)  # отмечаем как посещенный
            for neighbor in graph[node]:  # для каждого соседа этого узла
                if neighbor not in visited:  # если сосед еще не посещен
                    stack.append(neighbor)  # добавляем его в стек

def count_connected_components(graph, n):
    visited = set()  # множество для отслеживания посещенных узлов
    components = 0   # счетчик компонент связности
    
    for node in range(1, n + 1):
        if node not in visited:
            dfs(graph, node, visited)  # обходим всю компоненту связности
            components += 1
    
    return components

def gen_random_edges(n, m):
    edges = [] # список
    used_edges = set() # множество (удаляет дубликаты)
    
    while len(edges) < m:
        # случайный узел от 1 до n
        u = random.randint(1, n)
        v = random.randint(1, n)
        
        # проверяем: не петля? и не дубликат?
        if u != v and (u, v) not in used_edges and (v, u) not in used_edges:
            edges.append((u, v))
            used_edges.add((u, v))
    
    return edges

n = int(input("Введите количество узлов сети: "))
m = int(input("Введите число линий связи (ребер): "))

edges = gen_random_edges(n, m)

# создаем список из (n+1) пустых списков
graph = [[] for _ in range(n + 1)]

# циклом добавляем рёбра в граф
for u, v in edges:  # для каждого ребра (u, v) в списке ребер
    graph[u].append(v)  # добавляем v в список соседей u
    graph[v].append(u)  # добавляем u в список соседей v

print("Сгенерированные узлы:")
for u, v in edges: # edges = [(1, 2), (2, 3), (1, 3)]  # пример списка ребер
    print(f"{u} {v}")

components = count_connected_components(graph, n) # находим количество компонент связности

print(f"Количество необходимых связей: {components - 1}")