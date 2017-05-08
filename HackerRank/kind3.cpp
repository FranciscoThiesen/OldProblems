#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define pb push_back
#define mp make_pair

int resp(string a, string b)
{
	int ans = 0;
	for(int i = 0; i < a.size(); ++i)
		if(a[i] <= b[i])
			ans++;
	return ans;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	string word;
	string ord;
	int maxTot= 0;
	int ans = 0;
	for(int i = 0; i < n; ++i)
	{
		char c;
		ord += i + '0';
		cin >> c;
		word += c;
	}
	word += word;
	for(int j = 0; j < n; ++j)
	{
		string tmp = word.substr(j,n);
		int q = resp(tmp, ord);
		if(q > maxTot)
		{
			maxTot = q;
			ans = j;
		}	
	}
	cout << ans + 1 << endl;
	return 0;
}