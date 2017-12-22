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

int n, m, rsp;
void doit(){
	rsp = 0;
	if(n < m) swap(n, m);
	set<int> sqr;
	set<int> num; 
	for(int i = 0; i*i <= n; ++i){
		sqr.insert(i*i);
	}
	rp(i, 1000) num.insert(i);
	for(const int& elem : sqr){
		auto it = num.find(n-elem);
		if(it != num.end()){
			if(*it * *it + sqrt(elem) == m) rsp++;
		}
	}
	printf("%d\n", rsp);
}

main(){
	scanf("%d %d", &n, &m);	
	doit();
}
