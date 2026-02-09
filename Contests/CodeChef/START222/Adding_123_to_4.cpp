#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int X, Y, Z;
        cin >> X >> Y >> Z;
        int result = 0;
        result = Y / 2 + min(X, Z);  
        cout << result << endl;
    }  
    return 0;
}