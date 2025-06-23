#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
private:
    vector<long long> tree;
    int size;

public:
    FenwickTree(int n) {
        size = n + 1; // 1-based indexing
        tree.resize(size, 0);
    }

    void update(int i, int x) {
        while (i < size) {
            tree[i] += x;
            i += (i & -i);
        }
    }

    long long query(int i) {
        long long sum = 0;
        while (i > 0) {
            sum += tree[i];
            i -= (i & -i);
        }
        return sum;
    }

    long long range_query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

int main() {
    int n, k;

    cout << "Введите количество улиц и количество операций (n k): ";
    cin >> n >> k;

    FenwickTree ft(n);

    cout << "\nВведите " << k << " операций:\n";
    cout << "Формат:\n";
    cout << " 1 i x — добавить x мм снега на улицу i\n";
    cout << " 2 u r — запрос суммы снега с улиц от u до r\n\n";

    for (int q = 0; q < k; ++q) {
        int type;
        cout << "Операция #" << q + 1 << " (тип 1 или 2): ";
        cin >> type;

        if (type == 1) {
            int i, x;
            cout << " Введите улицу (i) и снег (x): ";
            cin >> i >> x;
            ft.update(i, x);
        }
        else if (type == 2) {
            int u, r;
            cout << " Введите диапазон улиц (u r): ";
            cin >> u >> r;
            cout << " Суммарный снег: " << ft.range_query(u, r) << endl;
        }
        else {
            cout << " Неизвестный тип операции!\n";
        }
    }

    return 0;
}