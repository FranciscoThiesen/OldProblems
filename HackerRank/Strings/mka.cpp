#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    string a;
    string b;
    cin >> a >> b;
    unordered_multiset<char> A;
    unordered_multiset<char> B;
    for(auto& p : a)
        A.insert(p);
    for(auto& x : b )
        B.insert(x);
    int total = 0;
    for(int i = 0; i < 26; i++)
    {
        int q = A.count('a' + i);
        int w = B.count('a' + i);
        total += abs(q-w);
    }
    cout << total << endl;
    return 0;
}
