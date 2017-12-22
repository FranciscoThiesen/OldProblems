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

vi arr;

void genPerm(int n){
	set<vi> perms;
	rp(i, (1<<n)){
		vi p(n, 0);
		rp(j, n){
			if(i & (i << j)) p[j] = 1;
		}
		perms.insert(p);
	}
}

int main(){
	int n;
	scanf("%d", &n);
	arr.resize(n);
	rp(i, n){
		scanf("%d", &arr[i]);

	}
	return 0;
}


