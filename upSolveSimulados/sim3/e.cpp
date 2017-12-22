/*input
4
1 5
3 3
4 5
-1 -6
*/

#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mt make_tuple

typedef long long ll;
typedef pair<int, int> ii;

const ll INF = 1e17;
const int MAXN = 2501;
const int MAXM = 7501;


// vertices em g1 de 1 a n, vertices em g2 de n+1 a n+m
int n; 
vector<int> g1[MAXN];
vector<ii> nums(2501);
vector<tuple<ll, ll, ll> > ans;
int pair_g1[MAXN], pair_g2[MAXM];
ll dist[MAXN];
map<ll, int> resultsRev; // id de cada resultado
map<int, ll> results;

bool bfs() { 
    queue<int> q; 
    for (int u = 1; u <= n; u++) { 
        dist[u] = INF; 
        if (pair_g1[u] == 0) { 
            dist[u] = 0; 
            q.push(u); 
        } 
    } 
    dist[0] = INF; 
    while (!q.empty()) { 
        int u = q.front(); q.pop(); 
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
            ans.pb(mt(nums[u].fi, nums[u].se, results[v]));
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
        for (int u = 1; u <= n; u++) 
            if (pair_g1[u] == 0 && dfs(u)) 
                matching++; 
    return matching; 
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    int id = n+1;
    int a, b;
    for(int i = 1; i <= n; ++i){
        cin >> a >> b;
        nums[i] = mp(a,b);
        ll mult = 1ll * a * b;
        ll sub = 1ll * a - b;
        ll add = 1ll * a + b;
        if(resultsRev.find(mult) == resultsRev.end()){
            results[id++] = mult;
            resultsRev[mult] = id-1;
        }
        if(resultsRev.find(sub) == resultsRev.end()){
            results[id++] = sub;
            resultsRev[sub] = id-1;
        }
        if(resultsRev.find(add) == resultsRev.end()){
            results[id++] = add;
            resultsRev[add] = id-1;
        }
        //cout << "mult = " << resultsRev[mult] << " sub = " << resultsRev[sub] << " add = " << resultsRev[add] << endl;
        g1[i].pb(resultsRev[mult]);
        g1[i].pb(resultsRev[sub]);
        g1[i].pb(resultsRev[add]);
    }
    int cardinality = hk();
    //cout << cardinality << " miau " << ans.size() << endl;
    if(cardinality == n){
        for(const tuple<ll, ll, ll>& x : ans){
            ll i,j,k;
            i = get<0>(x);
            j = get<1>(x);
            k = get<2>(x);
            if(i + j == k){
                cout << i << " + " << j << " = " << k << endl;
            }
            else if(i*j == k){
                cout << i << " * " << j << " = " << k << endl;
            }
            else if(i - j == k){
                cout << i << " - " << j << " = " << k << endl;
            }
        }
    }
    else{
        cout << "impossible" << endl;
    }
    return 0;
}
