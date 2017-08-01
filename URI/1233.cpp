#include <iostream>
using namespace std;
 
long long phi(long long N) {
    long long ans = N;
    if (!(N & 1)) {
            ans >>= 1;
            while (!(N & 1))
                N >>= 1;
        }
    for (long long p = 3; p*p <= N; p += 2) {
            if (N % p == 0) {
                        ans /= p;
                        ans *= (p-1);
                        while (N % p == 0)
                            N /= p;
                    }
        }
 
    if (N > 1)
        ans = (ans/N)*(N-1);
 
    return ans;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    long long N;
    while (cin >> N)
        cout << phi(N)/2 << '\n';
    return 0;
}

