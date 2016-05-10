#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
int main()
{
	int a, b, c, d = 0;
	scanf("%d %d", &a, &b);
	//cout << a << endl << b;
	int x1[a];
	int x = 0;
	for(int i = 0; i < a; i++)
	{
		scanf("%d", &x1[i]);
		x += x1[i] * pow(b,(a-1-i));
	}
	//cout << x;
	scanf("%d %d",&c, &d);
	//cout << c << endl << d;
	int y = 0;
	int y1[c];
	for(int i = 0; i < c; i++)
	{
		scanf("%d", &y1[i]);
		y += y1[i] * pow(d,(c-1-i));
	}
	//cout << y << endl;
	if(x > y)
	{
		printf(">");
		cout << x << " " << y;
		return 0;
	}
	if(x == y)
		printf("=");

	else
		printf("<");
	return 0;

}