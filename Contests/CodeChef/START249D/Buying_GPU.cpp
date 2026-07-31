#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--)
    {
        ll x,y,z;
        cin >> x >> y >> z;
        if(z > y)
        {
           cout << ((x%(z-y) == 0) ? x /(z-y) :  x /(z-y) + 1 ) << endl;
        }
        else cout << "-1" << endl;

    }
    return 0;
}