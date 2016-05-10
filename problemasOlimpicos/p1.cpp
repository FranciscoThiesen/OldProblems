#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;
int main()
{
	int a, b, c, d, e, wa, wb, wc, wd, we, s, u;
	scanf("%d %d %d %d %d", &a , &b , &c, &d, &e);
	scanf("%d %d %d %d %d", &wa, &wb, &wc, &wd, &we);
	scanf("%d %d", &s, &u);
	int total = 0;

	total += max(150, (int)((float)(1 - a/250.0) * 500) - 50*wa);
	total += max(300, (int)((float)(1 - b/250.0) * 1000) - 50*wb);
	total += max(450, (int)((float)(1 - c/250.0) * 1500) - 50*wc);
	total += max(600, (int)((float)(1 - d/250.0) * 2000) - 50*wd);
	total += max(750, (int)((float)(1 - e/250.0) * 2500) - 50*we);
	total += 100*s;
	total -= 50*u;

	printf("%d\n", total);
	return 0;
}