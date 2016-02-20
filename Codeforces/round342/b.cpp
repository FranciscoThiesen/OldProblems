#include <cstring>
#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string a;
    string b;
    cin >> a;
    cin >> b;
    int match = 0;
    int equal = 0;
    int j = 0;
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i] == b[j])
        {
            equal++;
            j++;
        }
        else
        {
            equal = 0;
            j = 0;
        }    
        if(equal == b.size())
        {
            match++;
            equal = 0;
            j = 0;
        }

        
    }
    cout << match << endl;
    return 0;
}
