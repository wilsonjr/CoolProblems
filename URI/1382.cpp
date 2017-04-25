#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	
	int t, n;
	int v[10001];

	while( ~scanf("%d", &t) && t ) {
		for( int i = 0; i < t; ++i ) {
			scanf("%d", &n);
						
			for( int j = 1; j <= n; ++j ) 
				scanf("%d", &v[j]);
			
			int trocas = 0;
			for( int j = 1; j <= n; ++j ) {
				if( v[j] != j ) {
					swap(v[j], v[v[j]]);
					trocas++;
					--j;
				}
			}
			
			printf("%d\n", trocas);
		}

	}



	return 0;
}