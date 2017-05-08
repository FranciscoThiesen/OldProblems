#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string s;
	cin >> s;
	int op = 0;
	for(auto& p : s)
	{
		if(p == 'A')
			op++;
		else if(p == 'B')
		{
			op--;
			if(op < 0)
			{
				cout << "Nao" << endl;
				return 0;
			}
		}
	
	}
	if(op == 0)
		cout << "Sim" << endl;
	else
		cout << "Nao" << endl;
	return 0;
}