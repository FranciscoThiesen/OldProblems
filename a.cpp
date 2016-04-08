#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    int a, b;
    bool ceta = true;
    cin >> a >> b;
    int vec[b];
    for(int i = 0; i < b; ++i)
    {
        scanf("%d", &vec[i]);
    }
    for(int j = 1; j < b; ++j)
    {
        if(abs(vec[j] - vec[j-1]) > a)
        {
            ceta = false;
            break;
        }
    }
    if(ceta)
        cout << "YOU WIN" << endl;
    else
        cout << "GAME OVER" << endl;
    return 0;
}
