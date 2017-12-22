#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()
#define fr(i,a,b) for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n) fr(i,0,n)


typedef vector<int> vi;
const int maxn = 1e5 + 1;

main(){
	int a, b;
	while(scanf("%d %d", &a, &b) == 2){
		if(a + b == 0) break;
		vi freq(maxn, 0);
		int h = -1;
		int totalArea = 0;
		rp(i, a){
			int x;
			scanf("%d", &x);
			freq[x]++;
			h = max(h, x);
			totalArea += x;
		}
		int total = 0; // quantos blocos ja estao abaixo do corte
		double lim = totalArea - b; // quanto precisamos de area
		double cur = 0; // area abaixo do corte atual
		bool cut = false;
		if(fabs(lim) < 1e-9){
			puts(":D");
			continue;
		}
		if(lim < 0){
			puts("-.-");
			continue;
		}
		fr(i,1, h+1){
			int blk = a - total;	// quantos blocos temos na altura > i
			total += freq[i];
			if(lim - cur <= blk*1.0){
				// consigo resolver com um corte entre i-1 e i...
				double c = i - 1 + (lim-cur)/blk;
				cut = true;
				printf("%.4lf\n", c);
				break;
			}
			cur += blk;
		}
	}
}
