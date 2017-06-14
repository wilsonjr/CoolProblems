#include <queue>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

#define MAX 105

int p1[MAX];
int p2[MAX];
int p3[MAX];
short visitado[101][101][101];

typedef struct p {
	int n1, n2, n3;
	p(int n): n1(n), n2(n), n3(n) {}
	p(){}
} pilha;

int bfs(int n)
{
	queue<pilha> q;
	
	q.push(pilha(n));
	
	char value[10];
	value[3] = '\0';
	map<string, int> m;
	
	
	while( !q.empty() ) {
		
		pilha u = q.front();
		q.pop();
		
		if( !u.n1 && !u.n2 && !u.n3 )
			return 1;
			
		if( u.n1 > 0 && p1[u.n1]%3 == 0 && !visitado[u.n1-1][u.n2][u.n3]  ) {
			
			visitado[u.n1-1][u.n2][u.n3] = 1;
			pilha pp;
			pp.n1 = u.n1-1;
			pp.n2 = u.n2;
			pp.n3 = u.n3;	
			q.push(pp);
		}			
		
		if( u.n2 > 0 && p2[u.n2]%3 == 0 && !visitado[u.n1][u.n2-1][u.n3]  ) {
			
			visitado[u.n1][u.n2-1][u.n3] = 1;
			pilha pp;
			pp.n1 = u.n1;
			pp.n2 = u.n2-1;
			pp.n3 = u.n3;
			q.push(pp);
		}
		
		if( u.n3 > 0 && p3[u.n3]%3 == 0 && !visitado[u.n1][u.n2][u.n3-1]  ) {
			
			visitado[u.n1][u.n2][u.n3-1] = 1;
			pilha pp;
			pp.n1 = u.n1;
			pp.n2 = u.n2;
			pp.n3 = u.n3-1;
			q.push(pp);
		}
		
		if( u.n1 > 0 && u.n2 > 0 && (p1[u.n1]+p2[u.n2])%3 == 0 && !visitado[u.n1-1][u.n2-1][u.n3]  ) {
			
			visitado[u.n1-1][u.n2-1][u.n3] = 1;
			pilha pp;
			pp.n1 = u.n1-1;
			pp.n2 = u.n2-1;
			pp.n3 = u.n3;
			q.push(pp);			
		}
		
		if( u.n1 > 0 && u.n3 > 0 && (p1[u.n1]+p3[u.n3])%3 == 0 && !visitado[u.n1-1][u.n2][u.n3-1]  ) {
			
			visitado[u.n1-1][u.n2][u.n3-1] = 1;
			pilha pp;
			pp.n1 = u.n1-1;
			pp.n2 = u.n2;
			pp.n3 = u.n3-1;
			q.push(pp);
		}
		
		if( u.n2 > 0 && u.n3 > 0 && (p2[u.n2]+p3[u.n3])%3 == 0 && !visitado[u.n1][u.n2-1][u.n3-1]  ) {
			
			visitado[u.n1][u.n2-1][u.n3-1] = 1;
			pilha pp;
			pp.n1 = u.n1;
			pp.n2 = u.n2-1;
			pp.n3 = u.n3-1;
			q.push(pp);
		}
		
		if( u.n1 > 0 && u.n2 > 0 && u.n3 > 0 && (p1[u.n1]+p2[u.n2]+p3[u.n3])%3 == 0 && !visitado[u.n1-1][u.n2-1][u.n3-1]  ) {
			
			visitado[u.n1-1][u.n2-1][u.n3-1] = 1;
			pilha pp;
			pp.n1 = u.n1-1;
			pp.n2 = u.n2-1;
			pp.n3 = u.n3-1;
			q.push(pp);
		}
	
	}
	
	return 0;
}

int main()
{	
	int n = 0;
	
	while( ~scanf("%d", &n) && n ) {
		for(int i = 0; i < 101; ++i)
			for(int j=0; j < 101; ++j)
				for(int k=0; k < 101; ++k)
					visitado[i][j][k] = 0;
		
		for( int i = 0; i < n; ++i )
			scanf("%d%d%d", &p1[n-i], &p2[n-i], &p3[n-i]);		
		
		int q = bfs(n);
		printf("%d\n", q);
	
	}
	
	return 0;
}
