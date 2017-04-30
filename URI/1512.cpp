#include <cstdio>

using namespace std;

long long int mdc2(long long int a,long long int b)
{
    if(b == 0) return a;
    else
    return mdc2(b,a%b);
}
long long int mmc2(long long int a,long long int b)
{
    long long int div;
    if(b == 0) return a;
    else
     div = (a*b)/(mdc2(a,b));
    return (div);
}      
        
 
int main()
{
    long long int a,b,n,r1,r2,r3;
    while(scanf("%lld %lld %lld",&n,&a,&b) && a!=0 && b!=0 && n!=0)
    {
        r1=n/a;
        r2=n/b;
        r3=mmc2(a,b);
        n/=r3;
        r1+=r2;
        r1-=n;
        printf("%lld\n",r1);
         
    }
    return 0;
}