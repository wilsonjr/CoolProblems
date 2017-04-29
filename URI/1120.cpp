#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{
    char num;
    string num_contrato;

    while( (cin >> num >> num_contrato) && num != '0' && num_contrato != "0" && !cin.eof() ) {
        num_contrato.erase(remove(num_contrato.begin(), num_contrato.end(), num), num_contrato.end());
        int i = 0;
        for( ; i < num_contrato.size() && num_contrato[i] == '0'; ++i );

        if( i < num_contrato.size() ) {
            num_contrato =  num_contrato.substr(i, num_contrato.size());
        } else
            num_contrato.clear();

        if( num_contrato.size() == 0 )
            num_contrato.append("0");
        cout << num_contrato << endl;
    }



    return 0;
}
