#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <set>
#include <map>
#include <utility>

using namespace std;

#define pb push_back
#define fi first
#define se second
#define mp make_pair

#define TRACE(x...)
#define PRINT(x...) TRACE(printf(x)) 
#define WATCH(x) TRACE(cout << #x << " = " << x << endl)
#define WATCH(x) TRACE(cout << #x << " = " << x << endl)

const int INF = 0x3F3F3F3F; const int NEGINF = 0xC0C0C0C0; const int NULO = -1;
const double EPS = 1e-10;

int num1, num2;
double v;

double apostRecebe()
{

	if(num1 % 10000 == num2 % 10000)
		return v * 3000;

	if(num1 % 1000 == num2 % 1000)
		return v * 500;

	if(num1 % 100 == num2 % 100)
		return v * 50;


	int bicho1, bicho2;

	bicho1 = num1 % 100;
	bicho2 = num2 % 100;
	
	if((bicho1 >= 97 || bicho1 == 0) && (bicho2 >= 97 || bicho2 == 0))
	{
		return 16 * v;
	}
	if(ceil((double)bicho1 / 4.0) == ceil((double)bicho2 / 4.0))
		return 16 * v;

	return 0.0;
}

int main(void)
{

	cin >> v >> num1 >> num2;

	while(v + num1 + num2 > 0)
	{
		TRACE(cout << "num1: " << num1 << " / num2: " << num2 << endl;);

		double resp = apostRecebe();

		cout << fixed << setprecision(2);

		cout << resp << endl;

		cin >> v >> num1 >> num2;
	}

	return 0;
}