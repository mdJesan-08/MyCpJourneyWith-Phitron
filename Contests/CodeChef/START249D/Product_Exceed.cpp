#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    
    while (t--) {
        ll x, y , p;
        cin >> x >> y >> p;
        ll mv = 0;
        while( x* y < p)
        {
            if(x > y){ y++; mv++; }
            else{ x++; mv++;}
        }
        cout << mv << "\n";
        
    }
    return 0;
}