#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		long long p;
		long long accu;
		for(int i = 0; i < n; ++i)
		{
			cin >> p;
			if(i == 0)
			{
				accu = p;
				if(p%2 == 1)
					accu++;
				else
					accu--;
			}	
			else
			{
				if(p%2)
					accu ^= (p+1);
				else 
					accu ^= (p-1);
			}
		}
		if(accu == 0)
			cout << "L" << endl;
		else
			cout << "W" << endl;	
	}
	return 0;
}