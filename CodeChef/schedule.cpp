// https://www.codechef.com/MARCH17/problems/SCHEDULE
#include <bits/stdc++.h>
 
using namespace std;
 
#define all(v) (v).begin(), (v).end()
#define fi first
#define se second
#define mp make_pair
#define fi first
#define fr(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define fu(i, a) fr(i,0,a)
#define sz(a) a.size()
#define mt make_tuple
#define pb push_back
 
typedef vector<int> vi;

bool check(vi freq, int maxMin, int k)
{
	int flips = 0;
	if(maxMin == 1)//corner-case
	{
		int ans1 = 0;
		int ans2 = 0;
		bool rev = true;
		fu(i, sz(freq))
		{
			if(freq[i]%2 == 0)
			{
				ans1 += freq[i]/2;
				ans2 += freq[i]/2;
				rev = !rev;
			}
			else
			{
				if(rev)
				{
					ans1 += freq[i]/2 + 1;
					ans2 += freq[i]/2;
				}
				else
				{
					ans2 += freq[i]/2 + 1;
					ans1 += freq[i]/2;
				}
			}
			if(ans1 > k && ans2 > k)return false;
		}
 
	}
	else
	{
		fu(i, sz(freq))
		{
			if(freq[i] <= maxMin)continue;
			else flips += ceil((freq[i] - maxMin)/(maxMin+1.0));
			if(flips > k)return false;
		}
	}
	return true;
}
 
vi compress(string& s)
{
	vi f;
	int prev = s[0] - '0'; int cur = 1;
	fr(i, 1, sz(s))
	{
		if(s[i] - '0' == prev)cur++;
		else
		{
			if(cur > 2)
				f.pb(cur);
			cur = 1;
			prev = !prev;
		}
	}
	if(cur > 2)
		f.pb(cur);
	return f;
}
 
vi compressSpecial(string& s)
{
	vi f;
	int prev = s[0] - '0'; int cur = 1;
	fr(i, 1, sz(s))
	{
		if(s[i] - '0' == prev)cur++;
		else
		{
			f.pb(cur);
			cur = 1;
			prev = !prev;
		}
	}
	f.pb(cur);
	return f;
}
 
 
int bs(string s, int k)
{
	int lo = 1; 
	int hi = s.size();
	int mid;
	vi freq1 = compress(s);
	vi freqCornerCase = compressSpecial(s);
	while(lo < hi)
	{
		mid = (hi + lo)/2;
		if(mid == 1)//corner-case
		{
			if(check(freqCornerCase, mid, k))
				hi = mid;
			else
				lo = mid + 1;	
		}
		else
		{
			if(check(freq1, mid, k))
				hi = mid;
			else
				lo = mid + 1;
		}
	}
	return lo;
}
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	int n, k;
	while(t--)
	{
		cin >> n >> k;
		cin >> s;
		cout << bs(s, k) << endl;
	}
 
	return 0;
} 