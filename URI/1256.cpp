#include <cstdio>
#include <list>

using namespace std;

#define MAX 100

int main()
{
	int n, N, M, q;
	list<int> vet[MAX];
	
	while( ~scanf("%d", &n) )	
	{
		for( int k = 0; k < n; ++k ) 
		{
			scanf("%d%d", &M, &N);
			for( int i = 0; i < M; ++i )
				vet[i].clear();
			for( int i = 0; i < N; ++i )
			{
				scanf("%d", &q);
				vet[q%M].push_back(q);			
			}

			for( int i = 0; i < M; ++i ) 
			{
				printf("%d ->", i);
				list<int>::iterator it = vet[i].begin();
				for( ; it != vet[i].end(); ++it )
					printf(" %d ->", *it);
			
				printf(" \\\n");
			}
			if( k < n-1 )
				printf("\n");
		}
		
	}


	return 0;
}