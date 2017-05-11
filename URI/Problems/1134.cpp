/*input
8
1
7
2
2
4
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x;
	int a = 0;
	int g = 0;
	int d = 0;
	cin >> x;
	while(x != 4)
	{
		if(x == 1)
			a++;
		else if(x == 2)
			g++;
		else if(x == 3)
			d++;
		cin >> x;
	}
	printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n", a, g, d);
	return 0;
}