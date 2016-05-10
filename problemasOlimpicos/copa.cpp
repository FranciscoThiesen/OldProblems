#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
	int i = 1;
	while(i >= 0)
	{

		cin >> i;
		
		if(i >= 0)
		{
			if(i == 0)
				printf("vai ter copa!\n");
			else
				printf("vai ter duas!\n");
		}
		else
		{
			break;
			return 0;
		}
	}
}