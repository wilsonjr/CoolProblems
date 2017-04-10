/**
http://br.spoj.com/submit/CARDAPIO
*/

#include <cstdio>
#include <cstdlib>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

long maior = -1;

double E = 10e-10;




struct ponto {
    double x;
    double y;
    ponto():x(0), y(0) {}
    ponto(double xx, double yy):x(xx), y(yy) {}
};

struct reta {
    double A;
    double B;
    double C;
    reta():A(0), B(0), C(0) {}
    reta(double AA, double BB, double CC): A(AA), B(BB), C(CC) {}
};


bool colinear(ponto a, ponto b, ponto c)
{
    return (b.x - a.x) * (c.y - a.y) == (b.y - a.y) * (c.x - a.x);
}


void abc(struct reta& r, ponto a, ponto b)
{
    r.A = b.y-a.y;
    r.B = a.x-b.x;
    r.C = r.A*a.x + r.B*a.y;
}

bool interseccao(double& x, double& y, struct reta& r1, struct reta& r2)
 {
    double det = r1.A*r2.B - r2.A*r1.B;

    if( det ) {
        x = (r2.B*r1.C - r1.B*r2.C)/det;
        y = (r1.A*r2.C - r2.A*r1.C)/det;
        return true;
    }
    return false;
}

double distancia(struct ponto& a, struct ponto& b)
{
    return (b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y);
}

struct ponto pts[100];
int main()
{
    int n = 0;
    while( scanf("%d", &n) != EOF && n ) {
        for( int i = 0; i < n; ++i )
            scanf("%lf%lf", &pts[i].x, &pts[i].y);


        if( n < 3 )
            printf("%d\n", n);
        else {
            maior = 2;
            for( int i = 0; i < n-2; ++i )
                for( int j = i+1; j < n-1; ++j )
                    for( int k = j+1; k < n; ++k ) {
                        if(  !colinear(pts[i], pts[j], pts[k]) ) {
                            struct reta ab;
                            struct reta bc;
                            abc(ab, pts[i], pts[j]);
                            abc(bc, pts[j], pts[k]);
                            double dMAB = -ab.B*((pts[i].x+pts[j].x)/2) + ab.A*((pts[i].y+pts[j].y)/2);
                            double dMBC = -bc.B*((pts[j].x+pts[k].x)/2) + bc.A*((pts[j].y+pts[k].y)/2);
                            struct reta mab(-ab.B, ab.A , dMAB); /* C não está definido ainda */
                            struct reta mbc(-bc.B, bc.A, dMBC);


                            double x = 0;
                            double y = 0;
                            if( interseccao(x, y, mab, mbc) ) {
                                long aux = 0;
                                struct ponto p(x, y);
                                double dist = distancia(p, pts[i]);
                                for( int z = 0; z < n; ++z ) {
                                    double dd = distancia(p, pts[z]);
                                    if( abs(dd-dist) <= E )
                                        aux++;
                                }
                                maior = std::max(aux, maior);
                            }
                        }
                    }
            printf("%ld\n", maior);
        }
    }
    return 0;
}

