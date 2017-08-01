#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main()
{
    int v;
    scanf("%d", &v);
    if(v == 1)
        cout << "January" << endl;
    else if(v == 2)
        cout <<"February" << endl;
    else if(v == 3)
        cout << "March" << endl;
    else if(v == 4)
        cout << "April" << endl;
    else if(v == 5)
        cout << "May" << endl;
    else if(v == 6)
        cout << "June" << endl;
    else if(v == 7)
        cout << "July" << endl;
    else if(v == 8)
        cout <<"August" << endl;
    else if(v == 9)
        cout << "September" << endl;
    else if(v == 10)
        cout << "October" << endl;
    else if(v == 11)
        cout << "November" << endl;
    else
        cout << "December" << endl;
    return 0;
}
