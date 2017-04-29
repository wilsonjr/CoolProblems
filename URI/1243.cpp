#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    char enunciado[55];
    //freopen("quao_facil.sol", "w", stdout);
    while( fgets(enunciado, 55, stdin) != 0 )
    {

        string str(enunciado);
        istringstream iss(string(str.begin(), str.end()-1));
        string temp;

        int qtd_pal = 0;
        int soma = 0;
        while( getline(iss, temp, ' ') )
        {
            int comp = 0;
            bool flag = true;
            if( temp.size() == 1 && temp[0] == '.' || temp.size() == 0 )
                flag = false;
            for( int i = 0; i < (int)temp.size() && flag; ++i )
            {

                if( temp[i] == '.' && (i != (int)temp.size()-1) )
                    flag = false;
                else if( (int)tolower(temp[i]) >= (int)'a' && (int)tolower(temp[i]) <= (int)'z' )
                    comp++;
                else if( (int)tolower(temp[i]) >= (int)'0' && (int)tolower(temp[i]) <= (int)'9' )
                    flag = false;
            }
            if( flag )
            {
                qtd_pal++;
                soma += comp;
            }
        }

        int medio = qtd_pal != 0 ? soma/qtd_pal : 0;
        if( medio <= 3 )
            printf("250\n");
        else if( medio >= 6 )
            printf("1000\n");
        else
            printf("500\n");



    }



    return 0;
}
