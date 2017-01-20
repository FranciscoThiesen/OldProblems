#include <bits/stdc++.h>

#define endl '\n'
#define pb push_back
#define mp make_pair


using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	int z, o;
	cin >> z >> o;
	if(z - o >= 2)
	{
		cout << -1 << endl;
		return 0;
	}
	int x = min(z,o);
	string s;
	string s1;
	string s2;
	vector<pair<char, int> > palavra;
	if(o >= z)
	{
		for(int i = 0; i < x; ++i)
		{
			palavra.pb(mp('1', 1));
			palavra.pb(mp('0', 1));
		}
		palavra.pb(mp('1', 0));
		o -= x;
		z -= x;
		while(o > 0)
		{
			for(int k = 0; k < palavra.size(); ++k)
			{
				if(palavra[k].first == '1')
				{
					if(palavra[k].second == 1)
					{
						palavra[k].second++;
						o--;
					}
					else if(palavra[k].second == 0)
					{
						if(o == 2)
							palavra[k].second += 2;	
						else if(o == 1)
							palavra[k].second++;
						o -= palavra[k].second;
					}
				}
				if(o == 0)
					break;
			}
			if(o > 0)
			{
				cout << -1 << endl;
				return 0;
			}
		}
		for(auto& p : palavra)
		{
			for(int i = 0; i < p.second; ++i)
				s += p.first;
		}
		cout << s << endl;
		return 0;

	}
	else if(z > o)
	{
		for(int i = 0; i < x; ++i)
		{
			palavra.pb(mp('0', 1));
			palavra.pb(mp('1', 1));
		}
		palavra.pb(mp('0', 0));
		o -= x;
		z -= x;
		if(z == 1 || z == 0)
		{
			for(auto& p : palavra)
			{
				for(int i = 0; i < p.second; ++i)
					s += p.first;
			}
			if(z == 1)
				s += '0';
			cout << s << endl;
			return 0;
		}
		else
		{
			cout << -1 << endl;
			return 0;
		}          
		
	}
	return 0;
}