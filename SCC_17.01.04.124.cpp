#include <bits/stdc++.h>
#define GREY 1
#define WHITE 0
#define BLACK 2
using namespace std;

int color[100],n,e,mark;
vector <int> adj1[100];
vector <int> adj2[100];
stack <int> stk;
bool visited[100];

void DFS(int u) {
    color[u] = GREY;
    int sz = adj1[u].size();
    for(int i = 0; i < sz; ++i) {
        int v = adj1[u][i];
        if(color[v] == WHITE)
            DFS(v);
    }
    stk.push(u);
    color[u]=BLACK;
}

void DFS2(int u) {
    visited[u]=true;
    cout<<u<<" ";
    int sz = adj2[u].size();
    for(int i = 0; i < sz; ++i) {
        int v = adj2[u][i];
        if(visited[v] == false)
            DFS2(v);
    }
}
void findSCC(){
    mark=0;
    for(int u=0;u<n;u++){
        if(color[u]==WHITE){
            DFS(u);
        }
    }
    while(!stk.empty()){
        int u=stk.top();
        stk.pop();
        if(visited[u]==false){
            mark=mark+1;
            DFS2(u);
            cout<<endl;
        }
    }
}

int main() {
    int u, v;
    cout<<"Vertex:";
    cin>>n;
    cout<<"Edge:";
    cin>>e;
    cout<<"Adjacent vertices:"<<endl;
    for(int i = 0; i < e; ++i) {
        scanf("%d%d", &u, &v);
        adj1[u].push_back(v);
        adj2[v].push_back(u);
    }
    cout<<"Strongly Connected components:"<<endl;
    findSCC();
    cout<<"\nTotal Strongly Connected Component is:"<<mark<<endl;
}

