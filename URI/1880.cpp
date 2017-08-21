#include <bits/stdc++.h>

using namespace std;


int ehPalindromo(string str) {
	if (str.size() <= 1) return 1;
	if (str[0] != str.back()) return 0;
	return ehPalindromo(str.substr(1, str.size() - 2));
}

int ehCapicua(int num, int base) {
	int div, resto, i = 0;
	string conv;

	div = num;
	while (div) {
		resto = div % base;
		if (resto >= 10) {
			char c = (resto - 10 + 'a');
			conv = c + conv;
		} else {
			conv = to_string(resto) + conv;
		}
		div = div / base;
		i++;
	}

	if (ehPalindromo(conv)) return 1;
	return 0;
}

int main(){
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int existeCapicua = 0;
		int dec;
		cin >> dec;

		for (int base = 2; base <= 16; base++) {
			if (ehCapicua(dec, base)) {
				if (!existeCapicua) {
					cout << base;
					existeCapicua = 1;
				} else {
					cout << " " << base;
				}
			}
		}

		if (!existeCapicua) cout << "-1";

		cout << endl;
	}

	return 0;
}
