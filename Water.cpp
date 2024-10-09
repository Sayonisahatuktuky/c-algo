#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;  

    while (T--) {
        int N;
        cin >> N; 

        int H[N]; 
        for (int i = 0; i < N; i++) {
            cin >> H[i];
        }

        
        int maxLeft = -1, maxRight = -1;
        int A= -1, B = -1;

        for (int i = 0; i < N; i++) {
            if (H[i] > maxLeft) {
                maxRight = maxLeft;
                B = A; 
                maxLeft = H[i];
                A= i;  
            } else if (H[i] > maxRight) {
                maxRight = H[i];
                B = i;   
            }
        }

        if (A< B) {
            cout << A<< " " << B << endl;
        } else {
            cout << B << " " << A<< endl;
        }
    }

    return 0;
}
