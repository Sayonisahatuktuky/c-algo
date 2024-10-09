#include <bits/stdc++.h>
using namespace std;

bool divide(int N, int choco[]) {
    int total = 0;
    
    for (int i = 0; i < N; i++) {
        total += choco[i];
    }

    if (total % 2 != 0) {
        return false;
    }

    int target = total / 2;

    bool dp[target + 1];
    memset(dp, false, sizeof(dp)); 
    dp[0] = true;  

    for (int i = 0; i < N; i++) {
        for (int j = target; j >= choco[i]; j--) {
            dp[j] = dp[j] || dp[j - choco[i]];
        }
    }

    return dp[target];
}

int main() {
    int T;
    cin >> T; 

    while (T--) {
        int N;
        cin >> N; 

        int choco[N];
        for (int i = 0; i < N; i++) {
            cin >> choco[i];
        }

        if (divide(N, choco)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
