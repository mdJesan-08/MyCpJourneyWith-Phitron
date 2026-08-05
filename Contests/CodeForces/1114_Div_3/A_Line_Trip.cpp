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
        int n ,x ;
        cin >> n >> x;

        vector<int> arr(n);
        
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];

        }
        int minVol = INT_MIN;
        minVol = max( minVol, arr[0] - 0);
        for (int i = 1; i <= n-1; i++)
        {
            minVol = max( minVol, arr[i] - arr[i-1]);
        }
        minVol = max( minVol, (x - arr[n-1])*2);
        


        cout << minVol << endl;
    }
    return 0;
}