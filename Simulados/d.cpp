#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;

int main()
{
	double a, b, c;
	while(scanf("%lf %lf %lf", &a, &b, &c) != EOF)
	{
		double distGuarda = sqrt(144 + (a*a));
		double distFugitivo = 12;
		double tmpGuarda = distGuarda/c;
		double tmpFugitivo = 12/b;
		if(tmpFugitivo < tmpGuarda)
			cout << "N" << endl;
		else
			cout << "S" << endl;
	}
	return 0;
}