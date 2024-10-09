#include <bits/stdc++.h>
using namespace std;

bool getScores(int N, int M, int A[]) {
    int t= 1000 - M;  

    if (t== 0) {
        return true; 
    }
    if (t< 0) {
        return false; 
    }

    bool dp[t+ 1];
    memset(dp, false, sizeof(dp));
    dp[0] = true; 

    for (int i = 0; i < N; i++) {
        for (int j = t; j >= A[i]; j--) {
            dp[j] = dp[j] || dp[j - A[i]];
        }
    }

    return dp[t];
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M; 

        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }

        if (getScores(N, M, A)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
