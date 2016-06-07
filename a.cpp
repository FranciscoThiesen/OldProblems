#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <map>
#include <string>
using namespace std;

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0; const int NULO = -1;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0, double tol = EPS) { return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;}

int main()
{

	int x = 1, y = 1, n = 1;
	while(x + y + n != 0)
	{
		cin >> x >> y >> n;
		if(x + y + n == 0)
			break;
		int arr[x][y];
		for(int h = 0; h < y; ++h)
		{
			for(int w = 0; w < x; ++w)
			{
				int a;
				cin >> a;
				arr[w][h] = a;
				//scanf("%d", &arr[x][y]);
			}
		}

		int _42 = 0;
		int palSize = 0;
		for(int k = 0; k < x; ++k)
		{
			for(int i = 0; i < y; ++i)
			{
				if(arr[k][i] != 0)
				{	
					palSize++;
					if(i == y-1)
					{
						if(palSize >= n)
							_42++;
					}
				}
				else 
				{
					if(palSize >= n)
						_42++;
					palSize = 0;
				}
				if(i == y-1)
					palSize = 0;
			}
		}
		cout << _42  << endl;
	}
	return 0;
}