#include <bits/stdc++.h>
using namespace std;

class DSU {
    vector<long long int> parent, rank;
public:
    DSU(long long int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (long long int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    long long int find(long long int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unite(long long int u, long long int v) {
        long long int pu = find(u);
        long long int pv = find(v);
        if (pu == pv) return false;

        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};

pair<long long int, long long int> kruskalMST(long long int N, long long int E, vector<tuple<long long int, long long int, long long int>>& edges) {
 
    sort(edges.begin(), edges.end(), [](const tuple<long long int, long long int, long long int>& a, const tuple<long long int, long long int, long long int>& b) {
        return get<2>(a) < get<2>(b);
    });

    DSU dsu(N+1); 
    long long int totalCost = 0;
    long long int edgeCount = 0; 

    for (auto& edge : edges) {
        long long int A, B, W;
        tie(A, B, W) = edge;

        if (dsu.unite(A, B)) { 
            totalCost += W;
            edgeCount++;
        }
    }

    if (edgeCount == N - 1) {
       
        return {E - edgeCount, totalCost};
    } else {
        
        return {-1, -1};
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

    auto result = kruskalMST(N, E, edges);
    
    if (result.first == -1) {
        cout << "Not Possible" << endl;
    } else {
        cout << result.first << " " << result.second << endl;
    }

    return 0;
}
