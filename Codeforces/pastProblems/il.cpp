#include <cstdio>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int score[n];
    for(int i = 0; i < n; ++i)
    {
        scanf("%d", &score[i]);
    }
    int max = score[0];
    int min = score[0];
    int total = 0;
    for(int i = 1; i < n; ++i)
    {
        if(score[i] > max)
        {
            total++;
            max = score[i];
        }
        else if(score[i] < min)
        {
            total++;
            min = score[i];
        }
    }
    cout << total << endl;
}
