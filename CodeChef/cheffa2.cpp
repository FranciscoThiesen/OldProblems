/*input
3
3
2 3 1
2
2 2
3
1 2 3
*/
#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define all(v) (v).begin, (v).end()
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i, n) fr(i,0,n)
#define sz(a) static_cast<int>(a.size())
 
typedef vector<int> vi;
 
set<vi> seqs;
 
void genPerm(vi& k){
	if(seqs.find(k) != seqs.end()){
		return;
	}
	int t = sz(k);
	for(int i = t-1; i >= 1; --i){
		vi cpy = k;
		if(cpy[i] > 0 && cpy[i-1] > 0){
			if(i+1 > t-1){
				cpy.pb(1);
				cpy[i]--;
				cpy[i-1]--;
				genPerm(cpy);
			}
			else{
				cpy[i]--;
				cpy[i-1]--;
				cpy[i+1]++;
				genPerm(cpy);
			}
		}
	}
	seqs.insert(k);
}
main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		vi init(n);
		rp(i, n) scanf("%d", &init[i]);
		genPerm(init);
		cout << sz(seqs) << endl;
		seqs.clear();
	}
	return 0;
} 
