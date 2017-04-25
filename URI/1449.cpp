#include <sstream>
#include <string>
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <iterator>
#include <algorithm>

using namespace std;


int main()
{
    int t = 0;
    while( scanf("%d", &t) != EOF ) {
        for( int k = 0; k < t; ++ k) {
            int m = 0, n = 0;
            scanf("%d%d", &m, &n);
            getchar();
            map<string, string> dic;
            for( int i = 0; i < m; ++i ) {
                string line;
                getline(cin, line);
                string trad;
                getline(cin, trad);
                dic[line] = trad;
            }

            for( int i = 0; i < n; ++i ) {
                string line;
                getline(cin, line);
                istringstream iss(line);
                vector<string> tokens;
                copy(istream_iterator<string>(iss), istream_iterator<string>(), back_inserter<vector<string> >(tokens));
                for( int j = 0; j < tokens.size(); ++j ) {
                    if( dic[tokens[j]] == "" ) {
                        if( j < tokens.size()-1 )
                            printf("%s ", tokens[j].c_str());
                        else
                            printf("%s\n", tokens[j].c_str());
                    } else {
                        if( j < tokens.size()-1 )
                            printf("%s ", dic[tokens[j]].c_str());
                        else
                            printf("%s\n", dic[tokens[j]].c_str());
                    }
                }
            }
            printf("\n");
        }


    }

    return 0;
}

