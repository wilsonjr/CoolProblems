#include <cstdio>
#include <cmath>

#define MAX 100000

using namespace std;

bool flag = true;

int ordena(int* vet, int n)
{
    int trocas = 0;
    for( int i = 0; i < n; ) {
        if( vet[i] != i+1 ) {
            int qtd = abs((vet[i] - i) - 1);
            trocas = trocas + (2*(qtd)) - 1;
            int temp = vet[i+qtd];
            vet[i+qtd] = vet[i];
            vet[i] = temp;
        } else
            i++;
    }
    return trocas;
}

int main()
{
    int vet[MAX];
    int n = 0;

    while( scanf("%d", &n) != EOF && n ) {
        for( int i = 0; i < n; ++i )
            scanf("%d", &vet[i]);
        if( ordena(vet, n) % 2 == 0 )
            printf("Carlos\n");
        else
            printf("Marcelo\n");

    }

    return 0;
}
