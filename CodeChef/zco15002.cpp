// https://www.codechef.com/ZCOPRAC/problems/ZCO15002
#include <bits/stdc++.h>
 
using namespace std;
 
#define fi first
#define se second
#define all(v) (v).begin(), (v).end()
#define fr(i,a,b)for(int (i) = (a); (i) < (b); ++(i))
#define rp(i,n)fr(i,0,n)
#define pb push_back
 
int main()
{
	int n, k, cur;
	scanf("%d %d", &n, &k);
	vector<int> nums(n);
	rp(i,n)cin >> nums[i];
	sort(nums.begin(), nums.end());
	int resp = 0, idx;
	rp(i,n)
	{
		cur = nums[i];
		idx = upper_bound(nums.begin(), nums.end(), nums[i]+k-1) - nums.begin();
		resp += n - idx;
	}
	printf("%d\n", resp);
	return 0;
} 