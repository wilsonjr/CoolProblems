#include <cstdio>
#include <cmath>

bool is_prime(unsigned int n)
{
	int i = 2;
	unsigned int sqrt_of_n = ceil(sqrt(n));	
	
	for( ; i < sqrt_of_n; ++i )
		if( !(n % i) )
			return false;
			
	return true;
}

int main()
{
	int n = 0;
	int q = 0;
	
	while( scanf("%d", &n) != EOF ) 
		for( int i = 0; i < n; ++i ) {
			scanf("%d", &q);
			if( is_prime(q) )
				printf("Prime\n");
			else
				printf("Not Prime\n");
		
		}
	
	return 0;
}
