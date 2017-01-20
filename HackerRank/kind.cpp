#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define mp make_pair


using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> t;
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		t.pb(x);
	}
	for(int i = 0; i < n; ++i)
		t.pb(t[i]);
	
	int ans = 0;
	int maxTot = 0;
	int tmp = 0;
	int minu = 0;
	// calculando resposta comecando do ultimo
	for(int k = n-1; k < t.size()-1; ++k)
	{
		if(t[k] <= minu)
			tmp++;
		minu++;	
	}
	maxTot = tmp;
	ans = n-1;
	for(int k = n-2; k >= 0; --k)
	{
		cout << t[k] << " o tk da vez eh " << endl;
		int resp = tmp;
		if(t[k] == 0)
			resp++;
		if(t[k+n] <= n)
			resp--;
		cout << "o inicio eh o t[k] = " << t[k] << " e a resposta dele eh " << resp << endl;
		if(resp >= maxTot)
		{
			maxTot = resp;
			ans = k;
		}
                tmp = resp;
	}	
	cout << ans + 1 << endl;
	return 0;
	
}