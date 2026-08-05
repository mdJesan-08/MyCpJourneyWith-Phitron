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
        int n = 5;
        vector<int> arr(n);
        int cntThirty = 0, cntSixty = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if(30 <= arr[i])
            {
                cntThirty++;
                if(60 <= arr[i]) cntSixty++;
            }

        }
        bool okay = cntSixty >= 2 && cntThirty >= 4;

        if(okay) cout << "Pass"<< "\n";
        else cout << "Fail" << "\n";
        
        
    }
    return 0;
}