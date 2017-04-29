#include <string>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>

using namespace std;

const long long overflow = 2147483647;
const string ov = "2147483647";

long long to_long(string str)
{
    long long c = 0;

    for( int i = 0; i < (int)str.size(); ++i )
        c = c*10 + ((int)str[i] - (int)'0');
    return c;
}

int primeiro_valido(string str)
{
    for( int i = 0; i < (int)str.size(); ++i )
        if( str[i] != '0' ) return i;
    return 0;
}



int main()
{
    string str;
    //freopen("processador_out", "w", stdout);
    while( getline(cin, str) ) {
        string convert;
        bool flag = true;
        if( str.size() ) {
            for( int i = 0; i < (int)str.size(); ++i )
                if( ((int)str[i] >= (int)'0' && (int)str[i] <= (int)'9') ||
                    (tolower(str[i]) == 'o') || (str[i] == 'l') ) {
                    if( (tolower(str[i]) == 'o') ) {
                        convert.append(1, '0');
                    } else if( (str[i] == 'l') ) {
                        convert.append(1, '1');
                    } else {
                        convert.append(1, str[i]);
                    }
                } else if( str[i] != ' ' && str[i] != ',' ) {
                    flag = false;
                    break;
                }
            if( convert.size() != 0 ) {

                long long c = 0;
                if( convert.size()-primeiro_valido(convert) > ov.size() ) {
                    flag = false;
                }
                else {
                    c = to_long(convert);
                    if( c > overflow ) flag = false;
                }
                if( flag )
                    cout << c << endl;
                else
                    cout << "error" << endl;
            }else
                cout << "error" << endl;

        } else
            cout << "error" << endl;
    }



    return 0;
}
