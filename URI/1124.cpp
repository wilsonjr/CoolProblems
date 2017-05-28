#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int l = 0, c = 0, r1 = 0, r2 = 0;

    while( (cin >> l >> c >> r1 >> r2) && (l && c && r1 && r2) && !cin.eof() ) {
        if( min(l, c) < 2*max(r1, r2) )
            cout << 'N' << endl;
        else {
            int r = r1 + r2;
            int a = l - r;
            int b = c - r;
            if( (a*a) + (b*b) < r*r )
                cout << 'N' << endl;
            else
                cout << 'S' << endl;
        }
    }

    return 0;
}
