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

ull countOnes(ull n){
	ull resp = 0;
	for(ull x = 1; x < n; ++x){
		resp += __builtin_popcount(x);
	}
	return resp;
}

ull resp[64];

int main(){
	resp[0] = 0;
	resp[1] = 1;
	resp[2] = 4;
	for(ull x = 3; x < 64; ++x){
		resp[x] = resp[x-1]*2 + (1ull<<(x-1));
	}
	for(const ull& x : resp) cout << x << endl;
	cout << countOnes(6) << endl;
}

