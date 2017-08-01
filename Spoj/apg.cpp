#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <string.h>
#include <utility>
using namespace std;

int main()
{
	int n, to_rm = 1;
	while(n + to_rm != 0)
	{
		scanf("%d%d", &n, &to_rm);
		if(n + to_rm == 0)
			return 0;
		string num;
		cin >> num;
		vector<vector<int> > numPos(10);
		cout << n << " " << to_rm << endl;
		for(int i = 0; i < (int)num.size();i++)
		{
			int x = num[i] - '0';
			numPos[x].push_back(n-i);
			cout << numPos[x][n-i] << endl;
		}
		sort(numPos.rbegin(),numPos.rend());
		int curPos = n;
		string ans;
		for(int j = 0; j <(int) numPos.size(); j++)
		{	
			for(int k = 0; k < (int)numPos[j].size(); k++)
			{
				if(curPos - numPos[j][k] <= to_rm)
				{
					ans += to_string(numPos[j]);
					to_rm -= curPos - numPos[j][k];
					curPos = numPos[j][k] -1; 
				}
				if(to_rm == 0)
					break;
			}
			if(to_rm == 0)		
				break;

		}
		cout << ans << endl;
	}
	return 0;	
}
