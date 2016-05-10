#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n, nb;
	scanf("%d %d", &n, &nb);
	int s[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &s[i]);
	}
	int boxSize = s[n-1];
	int numbox = nb;
	int currentsize = 0;
	for(int i = n-1; i >= 0; i--)
	{
		currentsize += s[i];
		if(currentsize == boxSize)
		{
			numbox--;
			currentsize = 0;
		}
		if(currentsize > boxSize)
		{
			currentsize = 0;
			numbox--;
			i++;
		}
		if(numbox == 0 && i <= 1)
		{
			boxSize++;
			i = n;
		}
	}
	printf("%d",boxSize);
	return 0;
}