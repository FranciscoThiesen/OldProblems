#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
 
#define MAXN 100005
#define MAXM 200005
 
#define mp make_pair
#define fi first
#define se second
 
typedef pair<int, int> pii;
 
int n, m, e[MAXM][2];
vector<pii> g[MAXN];
int visv[MAXN], vise[MAXM];
 
void dfs(int u) {
    visv[u] = 1;
    while (g[u].size() > 0) {
        int v = g[u].back().fi, id = g[u].back().se;
        g[u].pop_back();
        if (!vise[id]) {
            vise[id] = 1;
            e[id][0] = u;
            e[id][1] = v;
            dfs(v);
        }
    }
}
 
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--, v--;
        g[u].push_back(mp(v, i));
        g[v].push_back(mp(u, i));
    }
    int fail = 0;
    for (int i = 0; i < n; i++)
        if (g[i].size() % 2 == 1)
            fail = 1;
    if (fail) {
        puts("NO");
        return 0;
    }
    memset(visv, 0, sizeof(visv));
    memset(vise, 0, sizeof(vise));
    dfs(0);
    for (int i = 0; i < n; i++)
        if (!visv[i])
            fail = 1;
    if (fail) {
        puts("NO");
        return 0;
    }
    puts("YES");
    for (int i = 0; i < m; i++)
        printf("%d %d\n", e[i][0]+1, e[i][1]+1);
}