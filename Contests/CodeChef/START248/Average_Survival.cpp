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
        int n; cin >> n;
        vector<int> arr(n);


        for (int i = 0; i < n; i++) cin >> arr[i];          

        // sort the array
        int len = n;
        sort(arr.begin(), arr.end());


        for(int i = 0; i <= n -1 ; i++)
        {
            if(arr[i] == arr[n-1])
            {
                len = n - i ;
                break;
            }
        }
        cout << len << "\n";
        
    }
    return 0;
}