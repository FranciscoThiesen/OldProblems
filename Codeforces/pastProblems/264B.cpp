#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
int main()
{
    int energy = 0;
    int n;
    int money = 0;
    scanf("%d", &n);
    int pylons[n+1];
    pylons[0] = 0;
    for(int i = 1; i <= n; ++i)
        scanf("%d", &pylons[i]);
    for(int j = 0; j < n; ++j)
    {
        if(pylons[j] < pylons[j+1])
        {
            if(energy >= pylons[j+1]-pylons[j])
            {
                energy -= pylons[j+1]-pylons[j];
            }
            else
            {
                money += pylons[j+1]-pylons[j]-energy;
                energy = 0;
            }
        }
        else if(pylons[j] >= pylons[j+1])
        {
            energy += pylons[j] - pylons[j+1];
        }
    }
    cout << money << endl;
    return 0;
}
