#include <bits/stdc++.h>
using namespace std;

// চারটি দিকে চলাচলের জন্য ডিরেকশন
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// গ্রিডের ভিতরে থাকা কিনা চেক করা
bool isValid(int x, int y, int N, int M, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    return (x >= 0 && x < N && y >= 0 && y < M && grid[x][y] == '.' && !visited[x][y]);
}

// BFS ফাংশন যা একটি কম্পোনেন্ট এক্সপ্লোর করে এবং তার আকার রিটার্ন করে
int bfs(int startX, int startY, int N, int M, vector<vector<char>>& grid, vector<vector<bool>>& visited) {
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;

    int area = 0;

    while (!q.empty()) {
        // auto [x, y] = q.front();   // C++17 structured binding (not supported in C++11/14)
        int x = q.front().first;      // Use first and second instead
        int y = q.front().second;
        q.pop();
        area++;

        // চারটি দিকে যাওয়ার চেষ্টা
        for (int i = 0; i < 4; i++) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY, N, M, grid, visited)) {
                visited[newX][newY] = true;
                q.push({newX, newY});
            }
        }
    }

    return area;
}

int findMinArea(int N, int M, vector<vector<char>>& grid) {
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    int minArea = INT_MAX;
    bool foundComponent = false;

    // গ্রিডের প্রতিটি সেল ভিজিট করা
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                foundComponent = true;
                int area = bfs(i, j, N, M, grid, visited);
                minArea = min(minArea, area);
            }
        }
    }

    return foundComponent ? minArea : -1;
}

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> grid(N, vector<char>(M));

    // গ্রিড ইনপুট নিচ্ছি
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    int result = findMinArea(N, M, grid);
    cout << result << endl;

    return 0;
}
