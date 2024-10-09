#include <bits/stdc++.h>
using namespace std;

int knapsack(int N, int W, int weights[], int values[]) {
    int dp[N + 1][W + 1];

    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[N][W];
}

int main() {
    int T;
    cin >> T; 

    while (T--) {
        int N, W;
        cin >> N >> W;  

        int weights[N], values[N];
        for (int i = 0; i < N; i++) {
            cin >> weights[i]; 
        }
        for (int i = 0; i < N; i++) {
            cin >> values[i];
        }

        cout << knapsack(N, W, weights, values) << endl;
    }

    return 0;
}
