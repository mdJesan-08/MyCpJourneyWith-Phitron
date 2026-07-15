#include <bits/stdc++.h>
using namespace std;

int main() {
  
    long long int t; cin >> t;
    while(t--)
    {
        long  long int n,x,y;
        cin >> n >> x >> y;
        vector<long long int> arr(n);
        map<long long int, long long int> freq;
        
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
            freq[arr[i]]++;
        }

        sort(arr.begin(), arr.end());

        
    }
    return 0;
}