#include <bits/stdc++.h>

#define V 4
#define GREY 1
#define WHITE 0
#define BLACK 2

using namespace std;

int color[V];
vector <int> adj[V];

void DFS(int u) {
    color[u] = GREY;
    int sz = adj[u].size();

    for(int i = 0; i < sz; ++i) {
        int v = adj[u][i];

        if(color[v] == WHITE)
            DFS(v);
    }

    color[u] = BLACK;
    printf("%d ", u);
}

int main() {
    int n, e;
    scanf("%d%d", &n, &e);
    for(int i = 1; i <= n; ++i)
        adj[i].clear();

    for(int i = 0; i < e; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(2);
}
