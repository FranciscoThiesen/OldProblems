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
typedef unsigned int ui;
const int inf = 0x3f3f3f3f;
const int neginf = 0xc0c0c0c0;


int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		ui best = 0;
		ui v[n];
		rp(i, n) scanf("%u", &v[i]);
		rp(i, n){
			fr(j, i+1, n){
				ui soma = v[i] + v[j];
				rp(k, n){
					if(k == i || k == j) continue;
					best = max(best, soma ^ v[k]); 
				}
			}
		}
		printf("%u\n", best);
	}
	return 0;
}

