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
        ll n; cin >> n;
        ll maxi = 0; int pos = -1;
        for (ll i = 0; i < n; i++)
        {
            ll x; cin >> x;
            if(x > maxi)
            {
                pos = (i+1);
                maxi = x;
            }
        }

        cout << pos << "\n";
        
    }
    return 0;
}