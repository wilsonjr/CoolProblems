#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;

bool comp(const int& i )
{
    return i != 0;
}

int main()
{
    int n = 0;
    while( scanf("%d", &n) != EOF && n ) {
        getchar();
        for( int i = 0; i < n; ++i ) {
            vector<int> alfa(26, 0);
            string linha;
            getline(cin, linha);
            for( int j = 0; j < linha.size(); ++j )
                if( (int)linha[j] >= 97 && (int)linha[j] <= 122 )
                    alfa[((int)linha[j])-97] = 1;
            int qtd = count_if(alfa.begin(), alfa.end(), comp);
            if( qtd == 26 )
                printf("frase completa\n");
            else if( qtd >= 13 )
                printf("frase quase completa\n");
            else
                printf("frase mal elaborada\n");


        }


    }


    return 0;
}
