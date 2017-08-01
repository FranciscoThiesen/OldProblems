#include <bits/stdc++.h>

using namespace std;

unsigned long long fac(int n, int k)
{
	unsigned long long ans = n;
	int nxt = n-k;
	while(nxt >= 1)
	{
		ans*= nxt;
		nxt -= k;
	}
	return ans;
}


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		string n;
		int exc = 0;
		for(auto& p : s)
		{
			if(p != '!')
				n.push_back(p);
			else
			exc++;
		}
		int l = stoi(n);
		cout << fac(l, exc) << endl;
	}
	return 0;
}
