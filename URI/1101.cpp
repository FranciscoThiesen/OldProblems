#include <cstdio>
#include <iostream>
using namespace std;
int main()
{
    int a,b;
    cin >> a >> b;
    int sum = 0;
    for(int i = min(a,b); i <= max(a,b); ++i)
    {   
        printf("%d ", i);
        sum += i;
    }
    cout << "Sum="<< sum << endl;
    return 0;
}
