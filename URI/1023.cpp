#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

const int MAX = 201;


struct casa
{
    int qtd_pessoas;
    int consumo;
    int media_consumo;
    casa(): qtd_pessoas(0), consumo(0), media_consumo(0) {}
};

int vConsumo[MAX];

int main()
{
    int n = 0;
    int caso = 1;
    while( scanf("%d", &n) != EOF && n ) {


        for( int i = 0; i < MAX; ++i ) vConsumo[i] = 0;

        int consumo = 0;
        int moradores_cidade = 0;
        for( long i = 0; i < n; ++i ) {
            struct casa temp;
            scanf("%d%d", &temp.qtd_pessoas, &temp.consumo);
            vConsumo[temp.consumo/temp.qtd_pessoas] += temp.qtd_pessoas;
            consumo += temp.consumo;
            moradores_cidade += temp.qtd_pessoas;
        }
        if( caso > 1 ) printf("\n");
        printf("Cidade# %d:\n", caso);
        int i = 0;
        for( int j = 0; i < MAX; ++i )
            if( vConsumo[i] ) {
                if( j ) printf(" ");
                printf("%d-%d", vConsumo[i], i);
                j++;
            }

        //double consumo_medio = (consumo/moradores_cidade);
       // double consumo_medio=(((consumo*1.0)/(moradores_cidade*1.0))-0.0049999999);
       // printf("\nConsumo medio: %.2f m3.", consumo_medio);

        double int_part;
        int frac_part;
        frac_part = (int) (modf ((double)consumo/moradores_cidade, &int_part) *100);

        if(frac_part < 10)
            printf("\nConsumo medio: %d.0%d m3.\n", (int)int_part, (int)frac_part);
        else
            printf("\nConsumo medio: %d.%d m3.\n", (int)int_part, (int)frac_part);

        caso++;


    }

    return 0;
}
