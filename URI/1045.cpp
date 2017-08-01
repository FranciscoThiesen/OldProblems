/*input
7.0 5.0 7.0
*/
#include <bits/stdc++.h>

using namespace std;

int main()
{
	float a, b, c;
	vector<float> n;
	cin >> a >> b >> c;
	n.push_back(a);
	n.push_back(b);
	n.push_back(c);
	sort(n.begin(), n.end());
	a = n[2];
	b = n[1];
	c = n[0];
	if(a >= b + c)
	{
		cout << "NAO FORMA TRIANGULO" << endl;
		return 0;
	}
	if(a*a == b*b + c*c)
		cout << "TRIANGULO RETANGULO" << endl;
	if(a*a > b*b + c*c)
		cout << "TRIANGULO OBTUSANGULO" << endl;
	if(a*a < b*b + c*c)
		cout << "TRIANGULO ACUTANGULO" << endl;
	if(a == b && b == c)
		cout << "TRIANGULO EQUILATERO" << endl;
	else if(a == b || b == c)
		cout << "TRIANGULO ISOSCELES" << endl;
	return 0;
}