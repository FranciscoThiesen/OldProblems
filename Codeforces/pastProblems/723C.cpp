#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int arr[m] = {0};
	vector<int> sngs;
	for(int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		sngs.push_back(x);
		if(x <= m)
			arr[x-1]++;
	}
	int ch = 0;
	int mn = n/m;
	vector<int> missin;
	for(int i = 0; i < m; ++i)
	{
		if(arr[i] < mn)
		{
			for(int j = 0; j < mn-arr[i]; ++j)
				missin.push_back(i+1);
		}
		
	}
	int cur = 0;
	for(int i = 0; i < sngs.size(); ++i)
	{
		if(sngs[i] <= m)
		{
			if(arr[i] > mn && arr[i] != missin[cur])
			{
				cout << "pru" << endl;
				arr[i-1]--;
				sngs[i] = missin[cur];
				arr[missin[cur]-1]++;
				cur++;
				ch++;
			}
		}
		else
		{
			cout << "pru2" << endl;
			sngs[i] = missin[cur];
			arr[missin[cur]-1]++;
			cur++;
			ch++;
		}
		if(cur == missin.size())
			break;
	}
	cout << mn << " " << ch << endl;
	for(auto& p : sngs)
		cout << p << " ";
	cout << endl;
	return 0;

}