#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        vector<long long int > arr(n);
        
        for ( int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        // cout << arr.size() << " is size" << endl;
        for ( int i = arr.size() - 2; i >= 0; i--) 
        {
            long long int newVal = arr[i] + arr[i+1];
            // cout << newVal << " ";
            arr[i] = newVal;


        }
        // cout << endl;

        if(arr[0] % 2 == 0 ) cout << "Yes" << endl;
        else cout << "No" << endl;
        
    }  
    return 0;
}