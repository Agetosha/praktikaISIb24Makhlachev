import random

def dfs(graph, start_node, visited):
    """DFS для поиска компоненты связности"""
    stack = [start_node]
    
    while stack:
        node = stack.pop()
        if node not in visited:
            visited.add(node)
            # Добавляем непосещенных соседей в стек
            for neighbor in graph[node]:
                if neighbor not in visited:
                    stack.append(neighbor)

def count_connected_components(graph, n):
    """Подсчитывает количество компонент связности в графе"""
    visited = set()
    components = 0
    
    for node in range(1, n + 1):
        if node not in visited:
            dfs(graph, node, visited)
            components += 1
    
    return components

def generate_random_edges(n, m):
    """Генерирует m случайных рёбер для графа с n узлами"""
    edges = []
    used_edges = set()
    
    while len(edges) < m:
        u = random.randint(1, n)
        v = random.randint(1, n)
        
        # Избегаем петель и дубликатов
        if u != v and (u, v) not in used_edges and (v, u) not in used_edges:
            edges.append((u, v))
            used_edges.add((u, v))
    
    return edges

# Считываем входные данные
n = int(input("Введите количество узлов сети: "))
m = int(input("Введите число линий связи (ребер): "))

# Генерируем случайные рёбра
edges = generate_random_edges(n, m)

# Создаем список смежности для графа
graph = [[] for _ in range(n + 1)]  # Индексы от 1 до n

# Добавляем рёбра в граф
for u, v in edges:
    graph[u].append(v)
    graph[v].append(u)  # Граф ненаправленный

# Выводим сгенерированные узлы
print("Сгенерированные узлы:")
for u, v in edges:
    print(f"{u} {v}")

# Находим количество компонент связности
components = count_connected_components(graph, n)

# Выводим минимальное количество рёбер для объединения
print(f"Количество необходимых связей: {components - 1}")

