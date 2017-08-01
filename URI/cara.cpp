#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a;
	cin >> a;
	while(a != 0)
	{
		int mary = 0;
		int john = 0;
		for(int i = 0; i < a; i++)
		{
			int d;
			cin >> d;
			if(d == 0)
				mary++;
			else
				john++;

		}
		cout << "Mary won " << mary << " times and John won " << john << " times" << endl;
		cin >> a;
	}
	return 0;
}