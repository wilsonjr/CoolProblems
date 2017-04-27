#include <vector>
#include <stack>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <iostream>

using namespace std;

int main()
{
    int n = 0, p = 0;

    while( scanf("%d%d", &n, &p) != EOF && n && p ) {
        vector<int > fila_pilha(p, 0);
        int pos = -1;
        int posj = -1;
        for( int i = 0; i < p; ++i ) {
            int aux = 0;
            scanf("%d", &aux);
            for( int j = 0; j < aux; ++j ) {
                int pilha = 0;
                scanf("%d", &pilha);
                if( pilha == 1 ) {
                    pos = i;
                    posj = j;
                }
            }
            fila_pilha[i] += aux;
        }

        if( !pos || pos == fila_pilha.size()-1 ) {
            printf("%d\n", (fila_pilha[pos] - posj) - 1);

        } else {
            int soma_esq = (fila_pilha[pos] - posj) - 1, soma_dir = (fila_pilha[pos] - posj) - 1;

            for( int i = pos-1; i >= 0 && fila_pilha[i] > posj; --i  )
                soma_esq += (fila_pilha[i]-posj);
            for( int i = pos+1; i < fila_pilha.size() && fila_pilha[i] > posj; ++i )
                soma_dir += (fila_pilha[i]-posj);

            printf("%d\n", min(soma_esq, soma_dir));

        }
    }
    return 0;
}
