#include <queue>
#include <stack>
#include <cstdio>

using namespace std;

struct identificacao {
	bool f;
	bool p;
	bool pq;
	identificacao( ):f(true), p(true), pq(true) {}
};

int main()
{
	int n = 0;
	
	while( scanf("%d", &n) != EOF ) {
		int flag = -1, num = -1;
		struct identificacao id;
		queue<int> fila;
		stack<int> pilha;
		priority_queue<int> pfila;
		
		for( int i = 0; i < n; ++i ) {
			scanf("%d%d", &flag, &num);
			if( flag == 1 ) {
				fila.push(num);
				pfila.push(num);
				pilha.push(num);			
			} else {
				int topfila = fila.front();
				fila.pop();
				int toppfila = pfila.top();
				pfila.pop();
				int topstack = pilha.top();
				pilha.pop();
				if( topfila != num )
					id.f = false;
				if( toppfila != num )
					id.pq = false;
				if( topstack != num )
					id.p = false;			
			}			
		}
		if( id.f ) {
			if( id.pq ) {
				if( id.p )
					printf("not sure\n");
				else
					printf("not sure\n");
			} else if( id.p ) 
				printf("not sure\n");
			else
				printf("queue\n");
			
		} else if( id.pq ) {
			if( id.p )
				printf("not sure\n");
			else
				printf("priority queue\n");
		} else if( id.p )
			printf("stack\n");
	   else
			printf("impossible\n");
	
	}

	return 0;
}




