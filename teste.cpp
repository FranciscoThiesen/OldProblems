#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    string linha;
    //getline(cin, linha);//lendo a primeira string vazia
    cin.ignore();    
    cin.ignore();
    for(int i = 0; i < t; ++i)
    {
        //cout << linha << "  " << endl;
        vector<int> numeros;
        while(getline(cin, linha))
        {
         //   cout << linha << endl;
            if(linha.empty())break;
            int numero = stoi(linha);
            numeros.push_back(numero);
        }

        for(auto& p : numeros)
            cout << p << "  ";
        cout << numeros.size() << endl;
        //cout << endl;
    }
    return 0;
}
