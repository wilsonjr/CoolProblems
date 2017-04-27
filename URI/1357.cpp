#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	map<string, char> paraConv;
	map<char, string> paraBraile;
	
	paraConv[".***.."] = '0';
	paraConv["*....."] = '1';
	paraConv["*.*..."] = '2';
	paraConv["**...."] = '3';
	paraConv["**.*.."] = '4';
	paraConv["*..*.."] = '5';
	paraConv["***..."] = '6';
	paraConv["****.."] = '7';
	paraConv["*.**.."] = '8';
	paraConv[".**..."] = '9';
	
	paraBraile['0'] = ".***..";
	paraBraile['1'] = "*.....";
	paraBraile['2'] = "*.*...";
	paraBraile['3'] = "**....";
	paraBraile['4'] = "**.*..";
	paraBraile['5'] = "*..*..";
	paraBraile['6'] = "***...";
	paraBraile['7'] = "****..";
	paraBraile['8'] = "*.**..";
	paraBraile['9'] = ".**...";
	
	int n = 0;


	
	while( ~scanf("%d", &n) && n ) {
		getchar();
		char op = getchar();
		if( op == 'S' ) {
			string str;
			cin >> str;

			for( int i = 0; i < 3; ++i ) {
				for( int j = 0; j < str.size(); ++j ) {					
					const char* s = paraBraile[str[j]].c_str();
					printf("%c", s[i*2]);
					printf("%c", s[i*2+1]);
					if( j < str.size()-1 )
						printf(" ");
					
				}
				printf("\n");
			}
		} else {
			vector<string> elems(n, "");
			string str;


			for( int i = 0; i < 3; ++i ) 
				for( int j = 0; j < n; ++j ) {
					cin >> str;
					elems[j] += str;
				}

			
			for( int i = 0; i < elems.size(); ++i )
				printf("%c", paraConv[elems[i]]);
			printf("\n");

		}	
	
	
	}
	
	return 0;
}
