#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

template<class t1, class t2>
struct less_second {
    typedef pair<t1, t2> type;
    bool operator()(type const& a, type const& b) const {
        if( a.second == b.second )
            return a.first > b.first;
        return a.second < b.second;
    }
};

int main()
{
    string palavra;
    int qtd = 0;

    while( cin >> palavra && !cin.eof() ) {
        if( qtd > 0 ) printf("\n");
        map<int, int> m;

        for( int i = 0; i < palavra.size(); ++i )
            m[static_cast<int>(palavra[i])]++;

        vector<pair<int, int> > vec(m.begin(), m.end());
        sort(vec.begin(), vec.end(), less_second<int, int>());

        for( vector<pair<int, int> >::size_type i = 0; i < vec.size(); ++i )
            printf("%d %d\n", vec[i].first, vec[i].second);

        qtd++;
    }

    return 0;
}
