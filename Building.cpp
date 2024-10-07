#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<long long int> parent, rank;
public:
    DSU(long long int N) {
        parent.resize(N + 1); 
        rank.resize(N + 1, 0);
        for (long long int i = 1; i <= N; i++) { 
            parent[i] = i;
        }
    }

    long long int find(long long int A) {
        if (A != parent[A]) {
            parent[A] = find(parent[A]); 
        }
        return parent[A];
    }

    bool unite(long long int A, long long int B) {
        long long int pA = find(A);
        long long int pB = find(B);
        if (pA == pB) return false; 

        if (rank[pA] > rank[pB]) {
            parent[pB] = pA;
        } else if (rank[pA] < rank[pB]) {
            parent[pA] = pB;
        } else {
            parent[pB] = pA;
            rank[pA]++;
        }
        return true;
    }
};

long long int kruskalMST(long long int N, vector<tuple<long long int, long long int, long long int>>& edges) {
 
    sort(edges.begin(), edges.end(), [](const tuple<long long int, long long int, long long int>& a, const tuple<long long int, long long int, long long int>& b) {
        return get<2>(a) < get<2>(b);
    });

    DSU dsu(N); 
    long long int totalCost = 0, edgeCount = 0;

    for (auto& edge : edges) {
        long long int A, B, W;
        tie(A, B, W) = edge;

        if (dsu.unite(A, B)) { 
            totalCost += W;     
            edgeCount++;
        }
    }

    if (edgeCount == N - 1) {
        return totalCost;
    } else {
        return -1;  
    }
}

 int main() {
    long long int N, E;
    cin >> N >> E;  

    vector<tuple<long long int, long long int, long long int>> edges;

    for (long long int i = 0; i < E; i++) {
        long long int A, B, W;
        cin >> A >> B >> W; 
        edges.push_back({A, B, W});
    }

    long long int result = kruskalMST(N, edges);
    cout << result << endl;

    return 0;
}
