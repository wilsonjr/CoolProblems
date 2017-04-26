#include <cstdio>
#include <cmath>

using namespace std;

int distancia(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
}

int main()
{
    int n = 0;

    while( ~scanf("%d", &n) && n ) {
        int dentroc = 0, bordac = 0, dentrop = 0, bordap = 0;
        int x, y, cx, cy, r1, r2;

        scanf("%d%d%d%d", &cx, &cy, &r1, &r2);
        for( int i = 0; i < n; ++i ) {
            scanf("%d%d", &x, &y);
            int dist = distancia(cx, cy, x, y);
            if( dist < r1 )
                dentroc++;
            else if( dist >= r1 && dist <= r2 )
                bordac++;
            scanf("%d%d", &x, &y);
            dist = distancia(cx, cy, x, y);
            if( dist < r1 )
                dentrop++;
            else if( dist >= r1 && dist <= r2 )
                bordap++;
        }

        if( dentroc > dentrop )
            printf("C > P\n");
        else if( dentrop > dentroc )
            printf("P > C\n");
        else {
            if( bordac > bordap )
                printf("C > P\n");
            else if( bordap > bordac )
                printf("P > C\n");
            else
                printf("C = P\n");
        }


    }




    return 0;
}
