#include <cstdio>
#include <map>

using namespace std;

#define MAX 100005

int v[MAX];
int mm[MAX];
int mInv[MAX];

void init(long n)
{
    for( long i = 0; i <= n; ++i )
        v[i] = 1;
}

int main()
{
    long n, m, a, b;
    //freopen("in", "r", stdin);
   // freopen("sol", "w", stdout);

    while( scanf("%ld%ld", &n, &m) != EOF ) {

        if( !n && !m ) break;
        init(n);
       // map<long, long> mm;
       // map<long, long> mInv;
        for( long i = 0; i < m; ++i ) {
            scanf("%ld%ld", &a, &b);
            v[a] = v[b] = -1;
            if( a != 1 && v[a-1] == -1 )
                a = mInv[a-1];
            if( b != n && v[b+1] == -1 )
                b = mm[b+1];
            mm[a] = b;
            mInv[b] = a;

            if( a == 1 )
                printf("* ");
            else printf("%ld ", (a-1));
            if( b == n )
                printf("*\n");
            else printf("%ld\n", (b+1));


        }
        printf("-\n");
    }



    return 0;
}
