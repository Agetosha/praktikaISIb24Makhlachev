#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <climits>

using namespace std;


vector<vector<int>> generatePyramid(int N, int minValue = 1, int maxValue = 9) {
    vector<vector<int>> pyramid(N);
    srand(time(0));

    for (int i = 0; i < N; ++i) {
        pyramid[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            pyramid[i][j] = minValue + rand() % (maxValue - minValue + 1);
        }
    }

    return pyramid;
}


pair<int, vector<int>> findMinPath(vector<vector<int>>& pyramid) {
    int N = pyramid.size();
    vector<vector<int>> dp = pyramid;
    vector<vector<int>> pathIndex(N);


    for (int j = 0; j < N; ++j) {
        pathIndex[N - 1].push_back(-1);
    }


    for (int i = N - 2; i >= 0; --i) {
        pathIndex[i].resize(i + 1);
        for (int j = 0; j <= i; ++j) {
            if (dp[i + 1][j] < dp[i + 1][j + 1]) {
                dp[i][j] += dp[i + 1][j];
                pathIndex[i][j] = j;
            } else {
                dp[i][j] += dp[i + 1][j + 1];
                pathIndex[i][j] = j + 1;
            }
        }
    }


    vector<int> path;
    int i = 0, j = 0;
    while (i < N) {
        path.push_back(pyramid[i][j]);
        if (i < N - 1)
            j = pathIndex[i][j];
        ++i;
    }

    return {dp[0][0], path};
}


void printPyramid(const vector<vector<int>>& pyramid) {
    for (const auto& row : pyramid) {
        for (int num : row)
            cout << num << " ";
        cout << endl;
    }
}

int main() {
    int N;
    cout << "Введите высоту горы: ";
    cin >> N;

    auto pyramid = generatePyramid(N);

    cout << "\nСгенерированная гора:\n";
    printPyramid(pyramid);

    auto [minSum, path] = findMinPath(pyramid);

    cout << "\nМинимальное время спуска: " << minSum << endl;
    cout << "Путь: ";
    for (int val : path)
        cout << val << " ";
    cout << endl;

    return 0;
}