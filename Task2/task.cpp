#include <iostream>
#include <vector>
#include <set>
#include <cstdlib>
#include <ctime>

using namespace std;

const int MAXN = 1001;

vector<int> graph[MAXN];
bool visited[MAXN];

void dfs(int node) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor])
            dfs(neighbor);
    }
}

set<pair<int, int>> generateEdges(int N, int M) {
    set<pair<int, int>> edges;
    srand(time(0));

    while ((int)edges.size() < M) {
        int u = rand() % N + 1;
        int v = rand() % N + 1;
        if (u == v) continue;
        if (u > v) swap(u, v);

        edges.insert({u, v});
    }

    return edges;
}

int main() {
    int N, M;
    cout << "Введите количество узлов (N <= 1000): ";
    cin >> N;
    cout << "Введите количество связей (M <= 1000): ";
    cin >> M;

    if (N > 1000,  M > 1000,  N < 1 || M < 0) {
        cout << "Ошибка: N и M должны быть в пределах 1..1000" << endl;
        return 1;
    }

    auto edges = generateEdges(N, M);

    cout << "\nСгенерированные связи:\n";
    for (auto [u, v] : edges) {
        cout << u << " " << v << endl;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int components = 0;
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            dfs(i);
            components++;
        }
    }

    cout << "\nМинимальное число дополнительных связей: " << (components - 1) << endl;

    return 0;
}