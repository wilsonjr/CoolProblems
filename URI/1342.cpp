#include <cstdio>


int trilha[10001];
int jogadores[11];
bool podem_jogar[11];

int main()
{
	int p, s, t1, t2, t3, n, d1, d2;	

	//freopen("dice.in", "r", stdin);

	while( ~scanf("%d%d", &p, &s) ) {
		if( !p && !s ) break;

		for( int i = 0; i < s+1; ++i )
			trilha[i] = 0;
		for( int i = 0; i < 11; ++i ) {
			jogadores[i] = 0;
			podem_jogar[i] = true;
		}

		scanf("%d%d%d", &t1, &t2, &t3);
		trilha[t1] = 1;
		trilha[t2] = 1;
		trilha[t3] = 1;

		scanf("%d", &n);
		int first = 0;
		int campeao = -1;
		for( int i = 0; i < n; ++i ) {
			scanf("%d%d", &d1, &d2);
			if( campeao == -1 ) {
				int j = first;

				while( true ) {
					if( !podem_jogar[j] )
						podem_jogar[j] = true;
					else {
						jogadores[j] += (d1+d2);
						if( jogadores[j] > s )
							campeao = j;
						else if( trilha[jogadores[j]] )
							podem_jogar[j] = false;
						
						j++;
						if( j == p )
							first = 0;
						break;
					}	
					j++;
					
					if( j == p ) 
						j = 0;
					
				}
				if( j != p )
					first = j;

			}
		}


		printf("%d\n", campeao+1);
	}

	return 0;
}
