// https://www.codechef.com/ZCOPRAC/problems/ZCO16001
#include <bits/stdc++.h>
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define rp(i, v) for(int (i) = 0; (i) < (v); ++(i))
#define sz(a) ((a).size())
 
 
int main()
{
	int n, k, x, top, repl;
	multiset<int, greater<int> > v1;
	multiset<int, greater<int> > v2;
	multiset<int, greater<int> > v3;
	multiset<int, greater<int> > v4;
	scanf("%d %d", &n, &k);
	rp(i, n){
		scanf("%d", &x);
		v1.insert(x);
		v3.insert(x);
	}
	rp(i, n){
		scanf("%d", &x);
 
		v2.insert(x);
		v4.insert(x);
	}
	rp(i, k)
	{
		top = *(v2.begin());
		repl = *(v1.rbegin());
		if(repl < top){
			v2.insert(repl);
			v1.insert(top);
			v1.erase(v1.find(repl));
			v2.erase(v2.find(top));
		}
		else break;
	}
	rp(i, k)
	{
		top = *(v3.begin());
		repl = *(v4.rbegin());
 
		if(repl < top){
			v3.insert(repl);
			v4.insert(top);
			v3.erase(v3.find(top));
			v4.erase(v4.find(repl));
		}
		else break;
	}
	cout << min(*(v1.begin()) + *(v2.begin()), *(v3.begin())+ *(v4.begin())) << endl;
	return 0;
 
}