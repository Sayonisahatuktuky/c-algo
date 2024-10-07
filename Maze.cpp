#include <bits/stdc++.h>
using namespace std;

const int N =1e3 + 10;
bool vis[N][N];

int dx[4] ={0, 0, -1, 1};
int dy[4] ={1, -1, 0, 0};

map<pair<int,int>,pair<int,int>> par;

int n,m;
char graph[N][N];

bool valid(int Ci,int Cj)
{
    if (Ci >= 0 && Ci < n && Cj >= 0 && Cj < m && graph[Ci][Cj] != '#' && !vis[Ci][Cj])
    {
        return true;
    }
    return false;
}

void bfs(int Si,int Sj)
{
    vis[Si][Sj] = true;

    queue<pair<int,int>> q;
    q.push({Si,Sj});

    while(!q.empty())
    {
        pair<int,int>node= q.front();
        q.pop();

        for(int i =0; i< 4; i++)
        {
            int Ci = node.first + dx[i];
            int Cj = node.second + dy[i];

            if(valid(Ci,Cj))
            {
                vis[Ci][Cj] = true;
                q.push({Ci,Cj});
                
                par[{Ci,Cj}] ={node.first, node.second};
                
                if(graph[Ci][Cj]== 'D') return;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    
    memset(vis, false, sizeof(vis));

    pair<int,int> x,y;

    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j< m; j++)
        {
            cin >>graph[i][j];
            if (graph[i][j] == 'R') x = {i,j};
            if (graph[i][j] == 'D') y = {i,j};
        }
    }

    bfs(x.first, x.second);

    if (!vis[y.first][y.second])
    {
        for(int i =0; i< n; i++)
        {
            for(int j =0; j< m; j++)
            {
                cout<<graph[i][j];
            }
            cout<<endl;
        }
        return 0;
    }

    int Xi = y.first, Yi = y.second;
    
    while(graph[Xi][Yi] != 'R')
    {
        if(graph[Xi][Yi] != 'D')
            
            graph[Xi][Yi] = 'X';
        
        int NXi = par[{Xi, Yi}].first;
        Yi = par[{Xi, Yi}].second;
        Xi = NXi;
    }

    for(int i =0; i< n; i++)
    {
        for(int j= 0; j< m; j++)
        {
            cout<< graph[i][j];
        }
        cout<< endl;
    }
}