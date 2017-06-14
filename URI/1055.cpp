#include <cstdio>
#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>

using namespace std;

const int MAX = 55;

int vet[MAX];




int main()
{
    int n = 0;
    while( scanf("%d", &n) != EOF ) {
        for( int k = 0; k < n; ++k ) {
            int soma = 0;
            int nn = 0;
            scanf("%d", &nn);
            for( int i = 0; i < nn; ++i )
                scanf("%d", &vet[i]);
            sort(vet, vet+nn, greater<int>());
            int mm = (nn / 2) - 1;
            if( nn % 2 != 0 )
                mm = nn/2;
            vector<int> vec_aux;
            vec_aux.push_back(vet[0]);
            int i = 1, j = nn-1;
            int counter = 1;
            while( counter < nn ) {
                int ai = abs(vet[i] - vec_aux.back());
                int bi = abs(vet[i] - vec_aux.front());
                int aj = abs(vet[j] - vec_aux.back());
                int bj = abs(vet[j] - vec_aux.front());

                int maior = max(ai, max(bi, max(aj, bj)));
                if( maior == ai ) {
                    vec_aux.push_back(vet[i++]);

                } else if( maior == bi ) {
                    vec_aux.insert(vec_aux.begin(), vet[i++]);
                } else if( maior == aj ) {
                    vec_aux.push_back(vet[j--]);
                } else if( maior == bj ) {
                    vec_aux.insert(vec_aux.begin(), vet[j--]);
                }
                counter++;
            }

            for( int i = 1; i < nn; ++i )
                soma += abs(vec_aux[i-1]-vec_aux[i]);

            printf("Case %d: %d\n", (k+1), soma);
        }
    }



    return 0;
}

