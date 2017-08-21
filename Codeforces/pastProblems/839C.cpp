#include <bits/stdc++.h>

using namespace std;

#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n) fr(i,0,n)
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define mt make_tuple
#define mp make_pair
#define sz(a) (int)(a.size())

typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;

const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;

const int maxn = 1e5 + 5;

vi adjList[maxn];
int n, dist[maxn];

long double go(int v){
	dist[v] = 0;
	long double sum = 0;
	int kids = 0;
	for(const int& x : adjList[v]){
		if(dist[x] == -1){
			sum += go(x);
			kids++;
		}
	}
	if(!kids) return 0;
	return sum/kids + 1;

}
int main(){
    scanf("%d", &n);
    rp(i, n-1){
        int a, b;
        scanf("%d %d", &a, &b);
        adjList[--a].pb(--b);
        adjList[b].pb(a);
    }
	memset(dist, -1, sizeof dist);
	printf("%.10Lf\n", go(0));
	return 0;
}

