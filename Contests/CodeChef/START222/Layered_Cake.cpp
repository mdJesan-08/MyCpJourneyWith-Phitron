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

       int m;
       cin >> m;

       vector<long long int > arr(n);
       
       for ( int i = 0; i < n; i++) {
           cin >> arr[i];
       }


       vector<long long int > arr2(m);
       
       for ( int i = 0; i < m; i++) {
           cin >> arr2[i];
       }

       int cnt = 0;

       for (int i = 0; i < n; i++) {
           for (int j = 0; j < m; j++) {
               if(arr[i] > arr2[j]) cnt++;
           }
       }
       
       cout << cnt << endl;
        
        
    }  
    return 0;
}