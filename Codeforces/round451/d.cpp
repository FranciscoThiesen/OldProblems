#include <bits/stdc++.h>
using namespace std;
#define sc(a) scanf("%d", &a)
#define sc2(a, b) scanf("%d %d", &a, &b)
#define sc3(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pri(x) printf("%d\n", x)
#define prie(x) printf("%d ", x)
#define mp make_pair
#define pb push_back
#define BUFF ios::sync_with_stdio(false);
#define db(x) cerr<< #x <<" == "<< x <<endl;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const ld pi = acos(-1);
const int MOD = 1e9+7;
const int N = 1e6+100;
int mapa[N], v[N],n,m,k;
int bit[N];
int main()
{
	sc3(n,m,k);
	for(int i=0;i<n;i++) sc(v[i]);
	sort(v, v+n);
	set<int> s;
	int idx = 0;
	int L = 1;
	int R = m;
	int cnt = 0;
	while(R<=1e6+10){
		while(idx < n and v[idx] <=R){
			s.insert(v[idx]);
			idx++;
		}
		while(s.size()>0 and *s.begin() < L){
			s.erase(s.begin());
		}
		while(s.size() >= k){
			auto it = s.end();
			it--;
			s.erase(it);
			cnt++;
		}
		R++, L++;
	}
	// for(int i=0;i<n;i++) v[i] = 1e6+10 - v[i];
	// sort(v, v+n);
	
 //  idx = 0;
	// L = 1;
	// R = m;
	// int cnt2 = 0;
	// s.clear();
	// while(R<=1e6+10){
	// 	while(idx < n and v[idx] <=R){
	// 		s.insert(v[idx]);
	// 		idx++;
	// 	}
	// 	while(s.size()>0 and *s.begin() < L){
	// 		s.erase(s.begin());
	// 	}
	// 	while(s.size() >= k){
	// 		auto it = s.end();
	// 		it--;
	// 		s.erase(it);
	// 		cnt2++;
	// 	}
	// 	R++, L++;
	// }

	pri(cnt );
	return 0;
}