#include <cstdio>
#include <cmath>

int main(){
	float n, m, a = 0;
	scanf("%f %f %f", &n, &m, &a);
	printf("%.0f\n", ceil(n/a) * ceil(m/a));
	return 0;
}