#include <bits/stdc++.h>
#include <string>

using namespace std;

#define pb push_back

typedef long long ll;

int main()
{
	int t;
	cin >> t;

	while(t != 0)
	{
		int sum = 0;
		int num = 0;
		int problemas[t] = {0};
		for(int i = 0; i < t; i++)
		{
			char c;
			cin >> c;
			int d = c - 'A';
			int tim;
			cin >> tim;
			string ver;
			cin >> ver;
			if(ver == "correct")
			{
				num++;
				sum += problemas[d] + tim;
			}
			else
				problemas[d] += 20;
		}
		cout << num << " " << sum << endl;
	}
	return 0;
}


3
A 120 incorrect
A 130 incorrect
A 200 incorrect
5
A 100 correct
B 110 incorrect
B 111 correct
C 200 correct
D 300 incorrect
0