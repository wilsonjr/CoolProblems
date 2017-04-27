#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int bb(int *vet, int ini, int fim, int key)
{
    if( ini <= fim ) {
        int meio = (ini+fim) / 2;
        if( vet[meio] == key )
            return meio;
        else if( vet[meio] < key )
            return bb(vet, meio+1, fim, key);
        else
            return bb(vet, ini, meio-1, key);
    } else
        return -1;
}


int main()
{
    int n = 0;

    while( scanf("%d", &n) != EOF ) {
        int* vet = (int*) malloc(n*sizeof(int));
        int* soma = (int*) malloc(n*sizeof(int));
        for( int i = 0; i < n; ++i ) {
            scanf("%d", &vet[i]);
            soma[i] = 0;
        }
        //sort(vet.begin(), vet.end());
        partial_sum(vet, vet+n, soma);
        sort(soma, soma+n);
        int count = 0;
        if( soma[n-1] % 3 == 0 ) {
            for( int i = 0; i < n; ++i ) {

                int j = bb(soma, 0, n-1, soma[i]+(soma[n-1]/3));
                if( j != -1 ) {
                    int k = bb(soma, 0, n-1, soma[i]+2*(soma[n-1]/3));
                    if( k != -1 ) count++;
                }


            }
            printf("%d\n", count);
        } else
            printf("0\n");
    }

    return 0;
}
