#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int t; cin >> t;

    while(t--)
    {
        int n; cin >> n;
        vector<long long int> arr(n);

        for(long long int i = 0; i < n; i++) cin >> arr[i];

        long long int remain = 0;
        bool possible = true;

        for(long long int i = 0; i < n-1; i++) 
        {
            if(arr[i] < (i+1)) {break; possible = false;}
            else
            {
                remain = arr[i] - (i+1);
                arr[i] = (i+1);
                arr[i+1] = arr[i+1] + remain;

            }


        }

        for(long long int i = 1; i < n; i++) 
        {
            if(arr[i]> arr[i-1]) continue;
            else 
            { 
                possible = false;
                break;
            }
        }

        if(possible) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }

    return 0;
}