#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n = 1;
	vector<int> sequence;
	while(cin >> n)
	{
		if(n != -999999)
			sequence.push_back(n);
		else
		{
			long long mx = sequence[0];
			long long s = (int)sequence.size();
			for(int i = 0; i < s; ++i)
			{
				long long beg = sequence[i];
				mx = max(beg, mx);
				for(int j = i + 1; j < s; ++j)
				{
					beg*= sequence[j];
					mx = max(beg, mx);		
				}
			}
			cout << mx << endl;
			sequence.clear();
		}
		
	}
	return 0;
}
