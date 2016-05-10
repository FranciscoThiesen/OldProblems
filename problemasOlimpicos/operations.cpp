#include <cstdio>

int main()
{
	int x = 0;
	int op = 0;
	scanf("%d", &op);
	for(int i = 0; i < op; i++)
	{
		char a,b,c;
		scanf("%c%c%c ", &a, &b, &c);
		if( a == '+' && b == '+')
			x++;
		if( a == '+' && c == '+')
			x++;
		if( b == '+' && c == '+')
			x++;
		if( a == '-' && b == '-')
			x--;
		if( b == '-' && c == '-')
			x--;
		if( a == '-' && c == '-')
			x--;
	}
	printf("%d\n", x);
	return 0;

}