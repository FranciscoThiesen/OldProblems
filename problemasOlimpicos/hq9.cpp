#include <string>
#include <cstdio>
#include <iostream>

using namespace std;
int main()
{
	string a;
	cin >> a;
	int j = 0;
	for(int i = 0; i < a.size(); i++)
	{
		if(a[i] == 'H' || a[i] == 'Q')
		{
			j++;
			break;
		}
		if(a[i] == '9')
		{

			j++;
			break;
		}

	}
	if(j == 0)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}