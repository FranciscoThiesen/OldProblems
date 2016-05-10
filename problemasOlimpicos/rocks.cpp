#include <cstdio>

int main()
{
	int n;
	scanf("%d", &n);
	char firstChar;
	scanf("%c", &firstChar);
	int removeSome = 0;
	for(int i = 0; i < n ; i++)
	{	

		char c;
		scanf("%c", &c);
		if( c == firstChar)
			removeSome++;
		firstChar = c;
	}
	printf("%d\n", removeSome++);
	return 0;
}