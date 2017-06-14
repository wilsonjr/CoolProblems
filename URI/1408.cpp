#include <vector>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <stdio.h>

using namespace std;

int main()
{
    int n = 0, l = 0;

    while( (scanf("%d%d", &n, &l)) != EOF && n && l ) {
        vector<int> vec(l, 0);
        for( int i = 0; i < l; ++i )
            scanf("%d", &vec[i]);
        int maior = -1;

        for( int i = 0; i < l; ++i ) {
            if( l-i < maior ) break;
            int q = 0;
            vector<int>::iterator it = upper_bound(vec.begin()+i, vec.end(), vec[i] + (n-1));
            if( it == vec.end() )
                q = (l - i);
            else
                q = distance(vec.begin()+i, it);
            maior = max(maior, q);
            if( maior == n ) break;

        }
        printf("%d\n", (n-maior));
    }

    return 0;
}
