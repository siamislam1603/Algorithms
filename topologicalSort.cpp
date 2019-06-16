#include <bits/stdc++.h>
#define GREY 1
#define WHITE 0
#define BLACK 2
using namespace std;

int color[100],n,e;
vector <int> adj[100];
stack <int> stk;

void DFS(int u) {
    color[u] = GREY;
    int sz = adj[u].size();
    for(int i = 0; i < sz; ++i) {
        int v = adj[u][i];
        if(color[v] == WHITE)
            DFS(v);
    }
    color[u]=BLACK;
    stk.push(u);
}

int main() {
    int u, v ,s;
    scanf("%d%d", &n, &e);
    for(int i = 0; i < e; ++i) {
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    cout<<"Starting Node:";
    cin>>s;
    DFS(s);
    cout<<"Topological Sort:";
    while(!stk.empty()){
        int top=stk.top();
        stk.pop();
        cout<<top<<" ";
    }
    cout<<endl;
}
