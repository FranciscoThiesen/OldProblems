/*input
12
*/
#include <bits/stdc++.h>

using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

int main(){
	int n;
	scanf("%d", &n);
	if(n == 2) printf("2\n");
	else if(n%2) printf("%d\n", n);
	else printf("%d\n", n-1);
	return 0;
}