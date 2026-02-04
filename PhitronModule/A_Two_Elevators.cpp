#include<bits/stdc++.h>
using namespace std;


int main()
{
    int T;
    cin >> T;
   
    while(T--) 
    {

        int a, b, c;
        cin >> a >> b >> c;

        // time taken by second elevator
        
        //time taken by 1st elevator
        int t_1 = a - 1;
        int t_2 = abs(c-b ) + c-1;
        if(t_1 > t_2) cout << 2 << endl;
        else if(t_1 < t_2)  cout << 1 << endl;
        else cout << 3 << endl;

    
    }  
    return 0;
}