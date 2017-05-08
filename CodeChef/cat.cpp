#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		int c, d, l;
		cin >> c >> d >> l;
		int dogLegs = d*4;
		if(d == 0)
		{
			int q = c*4;
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
			if((int)ceil((double)c/d) <= 2)
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
				int downCats = l/4;
				l -= downCats*4;
				if(downCats > c)
					cout << "no" << endl;
				else if(downCats == c)
					cout << "yes" << endl;
				else
				{
					int maxUpCats = d*2;
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