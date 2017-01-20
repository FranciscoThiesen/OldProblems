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
		int problemas[26];
		for(int i = 0; i < 26; i++)
			problemas[i] = 0;
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
				sum += (problemas[d] + tim);
			}
			else
				problemas[d] += 20;
		}
		cout << num << " " << sum << endl;
		cin >> t;
	}
	return 0;
}


