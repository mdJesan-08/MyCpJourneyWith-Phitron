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
        vector<int> arr(3);
        cin >> arr[0] >> arr[1] >> arr[2];
        sort(arr.begin(), arr.end());
        int cnt = 0;
        while(
        !( arr[0] == arr[1] || arr[0] == arr[2] || arr[1] == arr[2])
        )
        {
            arr[0]++;
            arr[2]--;
            cnt++;
            sort(arr.begin(), arr.end());
        }
        cout << cnt << endl;

   
    }
    return 0;
}