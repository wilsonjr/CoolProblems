#include <cstdio>
#include <vector>

using namespace std;

int main()
{	
	int n = 0;

	//freopen("crise.in", "r", stdin);
	//freopen("crise.out", "w", stdout);

	while( ~scanf("%d", &n) && n ) {
		
		if( n == 13 )
			printf("1\n");
		else {
			for( int i = 2; i <= 500; ++i ) {
				int count = 0, menor = -1;
				vector<int> mark(n+1, 0);
				mark[1] = 1;
				count++;
				int idx = 1;
				int k = 0;

				while( k < i  ) {
					idx++;
					if( !mark[(idx <= n ? idx : (idx % n ? idx%n : n))] )
						k++;							
				}

				while( count < n ) {
									
					while( k < i  ) {
						idx++;
						if( !mark[(idx <= n ? idx : (idx % n ? idx%n : n))] )
							k++;							
					}
					mark[(idx <= n ? idx : (idx % n ? idx%n : n))] = 1;					
					count++;
					if( count == n && (idx <= n ? idx : (idx % n ? idx%n : n)) == 13 ) {
						menor = i;
						break;
					}
					k = 0;
				}
				
				if( menor != -1 ) {
					printf("%d\n", menor);
					break;
				}
			}
		}


	}


	return 0;
}