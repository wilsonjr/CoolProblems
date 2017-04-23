/**
* https://www.urionlinejudge.com.br/judge/en/problems/view/1388
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>

using namespace std;

int find_next(vector<int>& seq, int i)
{
    for( int j = i; j < seq.size(); ++j )
        if( seq[j] == -1 )
            return j;
    return -1;
}

void sequencia(vector<int>& seq, vector<int>& turnos)
{
    int ultima_posicao = 1;
    fill(seq.begin(), seq.end(), -1);

    for( int i = 0; i < turnos.size(); ++i ) {
        int nxt = find_next(seq, turnos[i]);
        if( nxt != -1 )
            seq[nxt] = ultima_posicao++;
    }
    for( int i = 0; i < seq.size(); ++i ) {
        if( seq[i] == -1 )
            seq[i] = ultima_posicao++;
        if( i != seq.size()-1 )
            printf("%d ", seq[i]);
        else printf("%d", seq[i]);
    }


   printf("\n");
}

int main()
{
    int m = 0, n = 0;

    while( (scanf("%d%d", &n, &m)) != EOF ) {
        if( n == 0 && m == 0 )
            break;
        vector<int> temp(n);
        vector<int> turnos;
        if( m ) {
            for( int i = 0; i < m; ++i ) {
                int aux = 0;
                scanf("%d", &aux);
                turnos.push_back(aux);
            }
        }

        sequencia(temp, turnos);
    }
    return 0;
}