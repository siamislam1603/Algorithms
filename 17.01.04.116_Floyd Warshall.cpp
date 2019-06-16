#include<bits/stdc++.h>
#define INF 999
using namespace std;
int dist[50][50];

void Floyd_Warshall(int n)
{
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(dist[i][k] > dist[i][j]+dist[j][k])
                    dist[i][k] = dist[i][j] + dist[j][k];
            }
        }
    }

}
int main()
{
    int n,e;
    cin >> n >> e;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(i!=j)
                dist[i][j] = INF;
        }
    }

    for(int i=1; i<=e; i++){
        int u,v,w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }

    Floyd_Warshall(n);

    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            if(dist[i][j] == INF)
                cout << "INF" << "\t";
            else
                cout << dist[i][j] << "\t";
        }

        cout << endl;
    }
    return 0;
}

/**
5 6
1 2 10
2 3 15
1 5 50
2 4 30
4 5 10
3 4 10
*/
