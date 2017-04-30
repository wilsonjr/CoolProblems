#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct pos {
    double x;
    double y;
    double distancia;
    pos():x(0), y(0), distancia(0) {}
    void dist(struct pos& p) {
        distancia = sqrt( pow(p.x - x,2) + pow(p.y - y, 2) );
    }
};

bool comp(struct pos& a, struct pos& b)
{
    return a.distancia <  b.distancia;
}


int main()
{
    struct pos branca;
    int n = 0;

    while( scanf("%d", &n) != EOF && n ) {
        for( int i = 0; i < n; ++i ) {
            int c = 0;
            scanf("%d", &c);
            scanf("%lf%lf", &branca.x, &branca.y);
            vector<struct pos> vec(c, pos());
            for( int j = 0; j < c; ++j ) {
                scanf("%lf%lf", &vec[j].x, &vec[j].y);
                vec[j].dist(branca);
            }

            vector<struct pos>::iterator it = min_element(vec.begin(), vec.end(), comp);
            printf("%d\n", distance(vec.begin(), it)+1);

        }
    }



    return 0;
}



