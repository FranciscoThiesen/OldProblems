#include <cstdio>
#include <string>
#include <iostream>
using namespace std;
int main()
{
	int x;
	scanf("%d", &x);
	int i = 1;
	while(true)
	{
		int z = x + i;
		string num = to_string(z);
		if(num[0] != num[1] && num[0] != num[2])
			if(num[0] != num[3] && num[1] != num[2])
				if(num[1] != num[3] && num[2] != num[3])
				{	
					printf("%s\n", num.c_str());
					return 0;
				}
		i++;
	}
	return 1;
}