//E
#include <cstring>
#include <cstdio>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <set>
using namespace std;
#define pb push_back

int main()
{
	int n = 1;
	while(n != 0)
	{
		cin >> n;
		if(!n)
			break;
		int ant;
		cin >> ant;
		vector<int> restou;
		restou.pb(ant);
		for(int i = 1; i < n; ++i)
		{
			int x;
			cin >> x;
			if(x != ant)
				restou.pb(x);
			ant = x;
		}
		for(auto& p : restou)
			cout << p << " ";
		cout << "$" << endl;
	}
}