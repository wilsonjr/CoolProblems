#include <string>
#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
    
using namespace std;
 
    
int main()
{
    int n = 0;
     
    while( (scanf("%d", &n) != EOF) && n ) {
         for( int i = 0; i < n; ++i ) {
            string vec_str;
            cin >> vec_str;
            int q = 0;
            scanf("%d", &q);
             
            for( int j = 0; j < q; ++j ) {
                string temp;
                cin >> temp;
                int k = 0, z = 0;
                for( ; k < temp.size() && z < vec_str.size(); ++z ) {
                    if( temp[k] == vec_str[z] )
                        k++;
                }
                if( k >= temp.size() )
                    printf("Yes\n");
                else
                    printf("No\n");
            }
        }
    }   
    
    return 0;
}
