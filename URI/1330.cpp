/*input
4 4
6
1 1
1 4
2 2
4 1
4 2
4 4
4 3
4
4 2
3 2
2 2
3 1
0 0
*/
#include <bits/stdc++.h>

using namespace std;

#define INF  0x3f3f3f3f
#define MAXN 20005
#define MAXM 20005
#define pb push_back
#define mp make_pair

int n, m;
vector<int> g1[MAXN];
int pair_g1[MAXN], pair_g2[MAXM], dist[MAXN];
int mat[101][101];


bool bfs() {
    queue<int> q;
    for (int u = 1; u < MAXN; u++) {
        dist[u] = INF;
        if (pair_g1[u] == 0) {
            dist[u] = 0;
            q.push(u);
        }
    }

    dist[0] = INF;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g1[u].size(); i++) {
            int v = g1[u][i];
            if (dist[pair_g2[v]] == INF) {
                dist[pair_g2[v]] = dist[u] + 1;
                q.push(pair_g2[v]);
            }
        }
    }
    return dist[0] != INF;
}

bool dfs(int u) {
    if (u == 0)
        return 1;
    for (int i = 0; i < g1[u].size(); i++) {
        int v = g1[u][i];
        if (dist[pair_g2[v]] == dist[u] + 1 && dfs(pair_g2[v])) {
            pair_g1[u] = v;
            pair_g2[v] = u;
            return 1;
        }
    }
    dist[u] = INF;
    return 0;
}

int hk() {
    memset(pair_g1, 0, sizeof(pair_g1));
    memset(pair_g2, 0, sizeof(pair_g2));

    int matching = 0;
    while (bfs())
        for (int u = 1; u < MAXN; u++)
            if (pair_g1[u] == 0 && dfs(u))
                matching++;
    return matching;
}

int main() {
    int p, a, b;
    while(scanf("%d %d", &n, &m) == 2){
        if(!(n+m))return 0;
        for(int i = 0; i < MAXN; ++i) g1[i].clear();
        memset(mat, 0, sizeof(mat));
        memset(pair_g1, 0, sizeof pair_g1);
        memset(pair_g2, 0, sizeof pair_g2);
        scanf("%d", &p);
        while(p--){
            scanf("%d %d", &a, &b);
            mat[--a][--b] = 1;
        }
        //return 0;
        for(int lin = 0; lin < n; ++lin){
            for(int col = 0; col < m; ++col){
                int idx = lin * m + col + 1;
                if(idx%2 == 0) continue;
                if(lin + 1 < n){
                    if(!mat[lin][col] && !mat[lin+1][col]){
                        g1[idx/2 + 1].pb(n*m + (idx+m)/2);
                    }
                }
                if(col + 1 < m){
                    if(!mat[lin][col] && !mat[lin][col+1]){
                        g1[idx/2 + 1].pb(n*m + (idx+1)/2);
                    }   
                }
            }
        }
        //cout << "ahh" << endl;
        printf("%d\n", hk());
    }
    return 0;   
}