#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct piloto {
    int id;
    int pont;
    int pos;
    piloto(): id(0), pont(0), pos(0) {}
    piloto(int ii, int pontt): id(ii), pont(pontt) {}
};


void imprime(vector<struct piloto>& vec, int i)
{
    if( i > 0 && vec[i].pont == vec[i-1].pont ) {

        imprime(vec, i-1);
        printf("%d ", vec[i].id);
    } else
        printf("%d", vec[i].id);
}


bool comp(const piloto& i, const piloto& j)
{
    return i.pont > j.pont;
}

int main()
{
    int g = 0, p = 0, s = 0;

    while( scanf("%d%d", &g, &p) != EOF && g && p ) {
        vector<vector<struct piloto> > v(g, vector<struct piloto>(p, piloto()));
        for( int i = 0; i < g; ++i )
            for( int j = 0; j < p; ++j ) {
                int temp = 0;
                scanf("%d", &temp);
                v[i][j].id = j+1;
                v[i][j].pos = temp;
            }

        int s = 0, temp = 0;
        scanf("%d", &s);
        for( int i = 0; i < s; ++i ) {
            scanf("%d", &temp);
            vector<int> vInt(temp, 0);
            for( int j = 0; j < temp; ++j )
                scanf("%d", &vInt[j]);

            vector<int> pontos(v[0].size(), 0);
            vector<struct piloto> vetor(v[0].size(), piloto());
            for( int k = 0; k < vetor.size(); ++k )
                vetor[k].id = k+1;


            for( int k = 0; k < v.size(); ++k )
                for( int z = 0; z < vInt.size(); ++z ) {
                    int y = 0;
                    for( ; y < v[k].size() && v[k][y].pos != (z+1); ++y );
                    vetor[v[k][y].id-1].pont += vInt[z];
                }



            stable_sort(vetor.begin(), vetor.end(), comp);
            printf("%d", vetor[0].id);
            for( int k = 1; k < vetor.size(); ++k )
                if( vetor[k-1].pont == vetor[k].pont ) {
                    printf(" %d", vetor[k].id);
                } else
                    break;
            printf("\n");
        }
    }

    return 0;
}
