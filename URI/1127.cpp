#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <map>
#include <string>
#include <numeric>

using namespace std;

const long MAX = 100010;
const long MAX2 = 10010;

int original[MAX];
int dif_original[MAX];
int copia[MAX2];
int dif_copia[MAX2];

void mapeia(map<string, int>& m)
{
    m["C"] = 1;
    m["B#"] = 1;
    m["Db"] = 2;
    m["C#"] = 2;
    m["D"] = 3;
    m["Eb"] = 4;
    m["D#"] = 4;
    m["E"] = 5;
    m["Fb"] = 5;
    m["F"] = 6;
    m["E#"] = 6;
    m["F#"] = 7;
    m["Gb"] = 7;
    m["G"] = 8;
    m["Ab"] = 9;
    m["G#"] = 9;
    m["A"] = 10;
    m["Bb"] = 11;
    m["A#"] = 11;
    m["B"] = 12;
    m["Cb"] = 12;
}


void computeLPSArray(int* pat, int M, int *lps)
{
    int len = 0, // length of the previous longest prefix suffix
        i = 1;
    lps[0] = 0;

    while( i < M ) {
        if( pat[i] == pat[len] )
            lps[i++] = ++len;
        else {
            if( len ) // This is tricky. Consider the example AAACAAAA and i = 7.
                len = lps[len-1];
            else
                lps[i++] = 0;
        }
    }
}

bool KMPSearch(int* pat, int* txt, int m, int n)
{
    int M = m;
    int N = n;

    // create lps[] that will hold the longest prefix suffix values for pattern
    int* lps = (int*) malloc(sizeof(int)*M);
    int j = 0;

    // preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);

    int i = 0;
    while( i < N ) {
        if( pat[j] == txt[i] ) {
            i++;
            j++;
        }

        if( j == M ) {
            return true;
            j = lps[j-1];
        } else // mismatch after j matches
        if( pat[j] != txt[i] ) {
            // do not match lps[0..lps[j-1]] characters,
            // they will match anyway
            if( j )
                j = lps[j-1];
            else
                i++;
        }
    }
    free(lps);
    return false;
}




int main()
{
    map<string, int> mm;
    int n, m;
    mapeia(mm);
    string str;
    char aux[MAX];
    //freopen("plagio.in", "r", stdin);
    //freopen("plagio.out", "w", stdout);

    while( scanf("%d%d", &n, &m) != EOF && n ) {
    getchar();
        for( int i = 0; i < n; ++i ) {
            scanf("%s", aux);
//            cin >> str;
        str = string(aux);
            original[i] = mm[str];
        }
        for( int i = 0; i < m; ++i ) {
            scanf("%s", aux);
//            cin >> str;
        str = string(aux);
            copia[i] = mm[str];
        }

        for( int i = 1; i < n; ++i )
            dif_original[i-1] = original[i]-original[i-1] >= 0 ? original[i]-original[i-1] : original[i]+12-original[i-1];
        for( int i = 1; i < m; ++i )
            dif_copia[i-1] = copia[i]-copia[i-1] >= 0 ? copia[i]-copia[i-1] : copia[i]+12-copia[i-1];

     /*   printf("\n");
        for( int i = 0; i < m-1; ++i )
            printf("%d ", dif_copia[i]);
        printf("\n\n");
        for( int i = 0; i < n-1; ++i )
            printf("%d ", dif_original[i]);
        printf("\n\n");
*/
        if( KMPSearch(dif_copia, dif_original, m-1, n-1) == true )
            printf("S\n");
        else
            printf("N\n");

    }




    return 0;
}
