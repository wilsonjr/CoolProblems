#include <cstdio>
#include <vector>

using namespace std;

typedef struct itenspesos
{
    int item;
    int peso;
    itenspesos(int i, int p) : item(i), peso(p) {}
} itenspesos;

typedef struct mochila
{
    vector<vector<int> > dados;
    vector<vector<int> > mat01;
    vector<itenspesos> itens;

    void configura_atrib(const vector<itenspesos>& itens_pesos, int capacidade)
    {
        dados = vector<vector<int> >(itens_pesos.size()+1, vector<int>(capacidade+1, 0));
        mat01 = vector<vector<int> >(itens_pesos.size(), vector<int>(capacidade, 0));
        itens = itens_pesos;
    }

    void carrega_mochila()
    {
        for( int i = 1; i < (int)dados.size(); ++i )
            for( int j = 1; j < (int)dados[i].size(); ++j )
                if( itens[i-1].peso <= j )
                {
                    if( dados[i-1][j - itens[i-1].peso] + itens[i-1].item > dados[i-1][j] )
                    {
                        dados[i][j] = dados[i-1][j - itens[i-1].peso] + itens[i-1].item;
                        mat01[i-1][j-1] = 1;
                    }
                    else
                    {
                        dados[i][j] = dados[i-1][j];
                        mat01[i-1][j-1] = 0;
                    }
                }
                else
                {
                    dados[i][j] = dados[i-1][j];
                    mat01[i-1][j-1] = 0;
                }

    }

    void show_itens(int i, int j, int& valor)
    {
        if( i >= 0 && j >= 0 )
        {
            if( mat01[i][j] == 1 )
            {
                show_itens(i-1, j-itens[i].peso, valor);
                valor += itens[i].item;
            }
            else
                show_itens(i-1, j, valor);
        }
    }

} mochila;

int main()
{
    int n;

    while( ~scanf("%d", &n) && n )
    {
        mochila mo;
        vector<itenspesos> it;
        for( int i = 0; i < n; ++i )
        {
            int a, b;
            scanf("%d%d", &a, &b);
            it.push_back(itenspesos(a, b));
        }

        int m;
        scanf("%d", &m);

        mo.configura_atrib(it, m);
        mo.carrega_mochila();
        int valor = 0;
        mo.show_itens(mo.mat01.size()-1, mo.mat01[0].size()-1, valor);
        printf("%d\n", valor);

    }



    return 0;
}



