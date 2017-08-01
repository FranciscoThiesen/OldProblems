// https://www.codechef.com/ZCOPRAC/problems/ZCO12002
#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ub upper_bound
#define lb lower_bound
#define mp make_pair
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n) fr(i,0,n)
 
const int n = 100010;
 
int main()
{
	int n, x, y;
	scanf("%d %d %d", &n, &x, &y);
	vector<int> in(x);
	vector<int> out(y);
	vector<pair<int, int> > events(n);
	rp(i, n)
	{
		scanf("%d %d", &events[i].fi, &events[i].se);
	}	
	rp(i, x) scanf("%d", &in[i]);
	rp(i, y) scanf("%d", &out[i]);
	
	sort(all(in));
	sort(all(out));
 
	int best = 2e9;
 
	for(const auto &event : events)
	{
		//printf("Analisando o evento (%d, %d)\n", event.fi, event.se);
		int start = ub(all(in), event.fi) - in.begin() - 1;
		int end = lb(all(out), event.se) - out.begin();
		//printf("A melhor hora de chegada foi %d e a melhor hora de saida foi %d \n", in[start], out[end]);
		if(start >= 0 && end >= 0 && start < x && end < y)
		{
			best = min(best, out[end] - in[start] + 1);
		}
	}
	printf("%d\n", best);
	return 0;
} 