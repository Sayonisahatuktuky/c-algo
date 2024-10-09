#include <bits/stdc++.h>
using namespace std;

bool reach(int N) {
    if (N == 1) return true; 

  
    queue<int> q;
    bool vis[100001] = {false}; 

    q.push(1);
    vis[1] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        int X= current + 3;
        int Y = current * 2;

        if (X== N || Y == N) {
            return true;
        }
        if (X<= N && !vis[X]) {
            q.push(X);
            vis[X] = true;
        }

        if (Y <= N && !vis[Y]) {
            q.push(Y);
            vis[Y] = true;
        }
    }
    return false;
}

int main() {
    int T;
    cin >> T;  
    while (T--) {
        int N;
        cin >> N;  

        if (reach(N)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
