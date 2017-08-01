#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
typedef long long ll;

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		ll a, b;
		scanf("%lld %lld", &a, &b);
		ll x = pow(a*b, 1/3.0);
		while(x*x*x < a*b) ++x;
		while(x*x*x > a*b) --x;
		if(x*x*x == a*b && !(a%x) && !(b%x)) puts("Yes");
		else puts("No");
	}
}
