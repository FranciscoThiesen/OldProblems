#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int x = abs(b-a) + abs(c-a);
	int y = abs(a-b) + abs(b-c);
	int z = abs(c-a) + abs(c-b);
	printf("%d\n", min(x,min(y,z)));
	return 0;
}