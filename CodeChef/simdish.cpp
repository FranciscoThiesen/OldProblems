// https://www.codechef.com/APRIL17/problems/SIMDISH

#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	int t;
	cin >> t;
	while(t--)
	{
		set<string> rp1;
		for(int i = 0; i < 4; ++i)
		{
			string tmp;
			cin >> tmp;
			rp1.insert(tmp);
		}
		int count = 0;
		for(int i = 0; i < 4; ++i)
		{
			string tmp2;
			cin >> tmp2;
			if(rp1.find(tmp2) != rp1.end())
				count++;
		}
		if(count >= 2) cout << "similar" << endl;
		else cout << "dissimilar" << endl;
	}
	return 0;
} 