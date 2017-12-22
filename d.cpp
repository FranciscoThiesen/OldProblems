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

const int maxn = 1000005;

vi adjList[maxn];

int n, k, dist[maxn];

int str2Int(string& s){
	int res = 0;
	rp(i, k){
		if(s[i] == '1'){
			res += (1 << (k-i-1));
		}		
	}
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	queue<int> q;
	memset(dist, -1, sizeof dist);
	rp(i, n){
		string s;
		cin >> s;
		int x = str2Int(s);
		dist[x] = 0;
		q.push(x);
	}
	int mxDist = -1;
	int rsp = 0;
	while(!q.empty()){
		int topo = q.front(), tmp;
		q.pop();
		rp(i, k){
			if(topo & (1 << (i))){
				tmp = topo;
				tmp -= (1 << i);
			}
			else{
				tmp = topo;
				tmp += (1 << i);
			}
			if(dist[tmp] == -1){
				dist[tmp] = dist[topo] + 1;
				if(dist[tmp] > mxDist){
					rsp = tmp;
					mxDist = dist[tmp];
				}
				q.push(tmp);
			}
		}	
	}
	rp(i, k){
		if(rsp & (1 << (k-i-1)))putchar('1');
		else putchar('0');
	}
	return 0;
}

