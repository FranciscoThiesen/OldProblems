// https://www.codechef.com/JAN17/problems/CATSDOGS
#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		ll c, d, l;
		cin >> c >> d >> l;
		ll dogLegs = d*4;
		if(d == 0)
		{
			ll q = c*4;
			if(l == q)
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
		else if(l < dogLegs)
		{
			cout << "no" << endl;
		}
		else if(l == dogLegs)
		{
			if((ll)ceil((double)c/d) <= 2)
				cout << "yes" << endl;
			else
				cout << "no" << endl;
		}
		else
		{
			l -= dogLegs;
			if(l%4 != 0)
				cout << "no" << endl;
			else
			{
				ll downCats = l/4;
				l -= downCats*4;
				if(downCats > c)
					cout << "no" << endl;
				else if(downCats == c)
					cout << "yes" << endl;
				else
				{
					ll maxUpCats = d*2;
					if(downCats + maxUpCats >= c)
						cout << "yes" << endl;
					else
						cout << "no" << endl;
				}
			}
		}
	}
	return 0;
}  