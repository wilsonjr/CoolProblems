#include <cstdio>
#include <list>
#include <queue>
#include <cstring>
#include <string>
#include <iostream>
#include <stack>
#include <map>

#define MAX 2002

using namespace std;

typedef struct
{
    string nome;
    int visitado;
    int adj[MAX];
    int n;
} vertice;

int componentes[MAX];
vertice grafo[MAX];
vertice tgrafo[MAX];
map<string, int> M;
stack<int> st;
int pilha[MAX];
int idx_pilha;

inline string nega(string str)
{
    if( str[0] == '!' )
        return string(str.begin()+1, str.end());

    string s;
    s = "!";
    s.append(str);
    return s;
}

void init_grafo(int n)
{
    for( int i = 1; i < MAX; ++i )
    {
        grafo[i].n = 0;
        tgrafo[i].n = 0;
    }
}

void visitaComponente(int i)
{
    grafo[i].visitado = 1;

    int it = 0;
    int itend = grafo[i].n;

    for( ; it < itend; ++it )
        if( !grafo[grafo[i].adj[it]].visitado )
            visitaComponente(grafo[i].adj[it]);
    pilha[idx_pilha++] = i;
}

void visitaComponenteT(int i, int rotulo)
{
    tgrafo[i].visitado = 1;
    componentes[i] = rotulo;
    int it = 0;
    int itend = tgrafo[i].n;

    for( ; it < itend; ++it )
        if( !tgrafo[tgrafo[i].adj[it]].visitado )
            visitaComponenteT(tgrafo[i].adj[it], rotulo);
}

void componenteDfs(int n)
{
    for( int i = 1; i <= n; ++i )
        grafo[i].visitado = 0;
    for( int i = 1; i <= n; ++i )
        if( !grafo[i].visitado )
            visitaComponente(i);
}

bool componenteDfsT(int n)
{
    for( int i = 1; i <= n; ++i )
    {
        componentes[i] = 0 ;
        tgrafo[i].visitado = 0;
    }

    int rotulo = 1;

    while( idx_pilha > 0 )
    {
        int u = pilha[--idx_pilha];
        if( !tgrafo[u].visitado )
        {
            visitaComponenteT(u, rotulo);
            rotulo++;
            if( componentes[u] == componentes[M[nega(grafo[u].nome)]] )
                return false;

        }
    }
    return true;
}

bool nao_tem(int a, int b)
{
    int it = 0;
    for( ; it < grafo[a].n; ++it )
        if( grafo[a].adj[it] == b )
            return false;
    return true;
}

int main()
{
    int n = 0;
    int ins = 1;
    while( ~scanf("%d", &n) && n )
    {
        getchar();
        init_grafo(n);
        M.clear();
        string str1, str2;
        //memset(adjacencia, 0, sizeof(adjacencia));
        int idx = 1, a = 0, b = 0;
        int maiorN = -1;

        for( int i = 0; i < n; ++i )
        {
            char temp[30];
            char temp2[30];
            scanf("%s %s", temp, temp2);

            string str1(temp);
            string str2(temp2);

            string nstr1 = nega(str1);
            string nstr2 = nega(str2);

            if( M[nstr1] == 0 )
                M[nstr1] = idx++;
            if( M[str2] == 0 )
                M[str2] = idx++;
            a = M[nstr1];
            b = M[str2];
            maiorN = max(maiorN, max(a, b));
            //if( nao_tem(a, b) )
           // {
                grafo[a].adj[grafo[a].n++] = b;
                grafo[a].nome = nstr1;
                grafo[b].nome = str2;
                tgrafo[b].adj[tgrafo[b].n++] = a;
                tgrafo[a].nome = nstr1;
                tgrafo[b].nome = str2;
            //}

            if( M[nstr2] == 0 )
                M[nstr2] = idx++;
            if( M[str1] == 0 )
                M[str1] = idx++;
            a = M[nstr2];
            b = M[str1];
            maiorN = max(maiorN, max(a, b));
           //if( nao_tem(a, b) )
            //{
                grafo[a].adj[grafo[a].n++] = b;
                grafo[a].nome = nstr2;
                grafo[b].nome = str1;
                tgrafo[b].adj[tgrafo[b].n++] = a;
                tgrafo[a].nome = nstr2;
                tgrafo[b].nome = str1;
            //}
        }
        idx_pilha = 0;
        componenteDfs(maiorN);
        bool flag = componenteDfsT(maiorN);
        printf("Instancia %d\n", ins++);
        printf("%s\n\n", flag ? "sim" : "nao");


    }

    return 0;
}

