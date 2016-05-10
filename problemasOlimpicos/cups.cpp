#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>

using namespace std;
int main()
{
	float t1, t2, t3, m1, m2, m3, s;
	scanf("%f %f %f %f %f %f %f", &t1, &t2, &t3, &m1, &m2, &m3, &s);
	float trophies = t1 + t2 + t3;
	float medals = m1 + m2 + m3;
	float need = ceil(medals/10);
	need += ceil(trophies/5);
	if(s < need)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}