#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

using namespace std;

const int MAX = 70000;

struct evento {
    int hh, mm, ss;
    char flag;

    evento(): hh(0), mm(0), ss(0), flag('\?') {}
};

struct evento vet[MAX];

bool comp(const struct evento& a, const struct evento& b)
{
    if( a.hh > b.hh )
        return false;
    else if( a.hh < b.hh )
        return true;
    else {
        if( a.mm > b.mm )
            return false;
        else if( a.mm < b.mm )
            return true;
        else {
            return a.ss < b.ss;
        }
    }
}

int main()
{
    int n = 0;

    char str[20];
    char* pch = 0;
    while( scanf("%d", &n) != EOF && n ) {
        getchar();
        int qtdX = 0, qtdE = 0;
        for( int i = 0; i < n; ++i ) {
            gets(str);
            pch = strtok(str,": ");
            vet[i].hh = atoi(pch);
            pch = strtok(NULL, ": ");
            vet[i].mm = atoi(pch);
            pch = strtok(NULL, ": ");
            vet[i].ss = atoi(pch);
            pch = strtok(NULL, ": ");
            vet[i].flag = pch[0];
            if( vet[i].flag == 'X' )
                qtdX++;
            else if( vet[i].flag == 'E' )
                qtdE++;
        }
        int faltaX = n/2 - qtdX;
        int faltaE = n/2 - qtdE;

        int sequencia = 0;
        int maior = -1;
        sort(vet, vet+n, comp);
        for( int i = 0; i < n; ++i ) {
            if( vet[i].flag == '\?' ) {
                if( faltaE ) {
                    vet[i].flag = 'E';
                    faltaE--;
                } else if( faltaX ) {
                    vet[i].flag = 'X';
                    faltaX--;
                }
            }
            if( vet[i].flag == 'E' )
                sequencia++;
            else {
                maior = max(maior, sequencia);
                sequencia--;
            }
        }
        printf("%d\n", maior);
    }

    return 0;
}
