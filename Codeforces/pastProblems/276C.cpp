/*input
3 3
5 3 2
1 2
2 3
1 3
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

const int MAXN = 200010;

vector<int> arr(MAXN, 0);
vector<int> d(MAXN, 0);

ll resp = 0;

int main()
{
	int n, q, l, r;
	scanf("%d %d", &n, &q);	
	for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
	sort(arr.rbegin(), arr.rend());
	for(int i = 0; i < q; ++i){
		scanf("%d %d", &l, &r);
		l--;
		d[l] += 1;
		d[r] -= 1;
	}
	for(int i = 1; i < n; ++i)
		d[i] += d[i-1];

	sort(d.rbegin(), d.rend());

	for(int i = 0; i < n; ++i){
		resp += 1ll * arr[i] * d[i];
	}
	printf("%lld\n", resp);
	return 0;
}