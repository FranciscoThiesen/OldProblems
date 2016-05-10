#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int x, t;
	scanf("%d %d", &x, &t);
	string z;
	cin >> z;
	int j = 0;
	while(j < t)
	{
		for(int i = 0; i < z.size(); i++)
		{
			if(z[i] == 'B' && z[i+1] == 'G')
			{
				z[i] = 'G';
				z[i+1] = 'B';
				i++;
			}
		}
		j++;
	}
	z += '\n';
	cout << z;
	return 0;
}