#include <cstdio>
#include <vector>
#include <algorithm>
#include <iostream>
#include <utility>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		int a;
		scanf("%d", &a);
		vector<int> men;
		vector<int> women;
		for(int m = 0; m < a; m++)
		{
			int man;
			cin >> man;
			men.push_back(man);
		}
		for(int w = 0; w < a; w++)
		{
			int woman;
			cin >> woman;
			women.push_back(woman);
		}
		int total = 0;
		sort(women.begin(), women.end());
		sort(men.begin(),men.end());
		for(int p = 0; p < a; p++)
			total += women[p] * men[p];
		cout << total << endl;
	}
	return 0;
}