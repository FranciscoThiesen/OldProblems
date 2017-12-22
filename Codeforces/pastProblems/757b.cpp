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

map<int, int> qntd;
int arr[maxn];

void fill(int x){
	for(int i = 1; i*i <= x; ++i){
		if(x%i == 0){
			qntd[i]++;
			if(x/i != i) qntd[x/i]++;
		}
	}
}

int main(){
	int n;
	scanf("%d", &n);
	rp(i, n){
		scanf("%d", &arr[i]);
		fill(arr[i]);
	}
	int best = 1;
	rp(i, n){
		if(arr[i] != 1) 
			best = max(best, qntd[arr[i]]);
	}
	printf("%d\n", best);
	return 0;
}

