#include <bits/stdc++.h>
#define V 5
#define GREY 1
#define WHITE 0
#define BLACK 2

using namespace std;

int color[V];
vector <int> adj[V];
queue<int> q;

void bfs(int s) {
    color[s] = GREY;
    q.push(s);
    int u;
    int sz;
    while(!q.empty()){
        u=q.front();
        cout<<u<<" ";
        q.pop();
        sz=adj[u].size();
        for(int i = 0; i < sz; ++i) {
            int v = adj[u][i];
            if(color[v] == WHITE){
                q.push(v);
                color[v]=GREY;
            }
        }
    }
    cout<<endl;
}

int main() {
    int e;
    cout<<"No of edges:";
    cin>>e;
    for(int i = 0; i < e; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"BFS:";
    bfs(2);
}


