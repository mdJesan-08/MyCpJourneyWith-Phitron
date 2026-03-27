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

        vector<long long int > arr(n+1);
        
        for ( int i = 0; i < n+1; i++) cin >> arr[i];

        int mini = INT_MAX;
        int maxi  = INT_MIN;

        for ( int i = 0; i < n; i++) 
        {
           maxi = max(arr[i], arr[i+1]) ;
           mini = min(mini,maxi);    
        }

        cout << mini << endl;
            
        
    }  
    return 0;
}