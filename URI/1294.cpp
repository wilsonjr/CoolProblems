#include <cstdio>
#include <cstdlib>
#include <cmath>

using namespace std;


inline double fn(double x, double l, double w)
{
    return (4.*pow(x, 3)) + (-2.*pow(x, 2)*(l+w)) +  (x*l*w);
}


int main()
{
    double l = 0.0, w = 0.0;

    while( ~scanf("%lf%lf", &l, &w) )
    {
        double a = 12.;
        double b = -4.*(l+w);
        double c = l*w;
        double delta = sqrt(pow(b, 2) - 4.*a*c);
        double x1 = (-b + delta) / (2.*a);
        double x2 = (-b - delta) / (2.*a);

        double fnx1 = fn(x1, l, w);
        double fnx2 = fn(x2, l, w);
        if( fnx1 > fnx2 )
        {
            printf("%.3f 0.000 %.3f\n", x1, fmin(w,l)/2+1e-8);
        }
        else
        {
            printf("%.3f 0.000 %.3f\n", x2, fmin(w,l)/2+1e-8);
        }
    }

    return 0;
}

