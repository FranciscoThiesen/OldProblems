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
const int maxn = 10;
vector<string> vec(maxn);
int n;
int dist[maxn][maxn];

int calc(vi& v){
	vi prev(26, 0);
	int tot = 0;
	rp(i, n-1) tot += dist[v[i]][v[i+1]];
	return tot;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while( cin >> n){
		memset(dist, 0, sizeof dist);
		rp(i, n) cin >> vec[i];
		rp(i, n){
			vi prev(26, 0);
			for(const char& c : vec[i]) prev[c-'A']=1;
			fr(j, i+1, n){
				int rsp = 0;
				for(const char& c : vec[j]){
					if(prev[c-'A']){
						rsp++;
					}
				}
				dist[i][j] = dist[j][i] = rsp;
			}
		}
		vi ord;
		rp(i, n) ord.pb(i);
		sort(vec.begin(), vec.begin() + n);
		int resp = 1e5;
		do{
			resp = min(resp, calc(ord));
		}while(next_permutation(all(ord)));
		cout << resp << endl;	
	}
	return 0;
}

