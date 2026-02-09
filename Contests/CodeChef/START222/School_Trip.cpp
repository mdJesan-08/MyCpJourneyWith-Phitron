#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int X , N , K;
        cin >> N >> X >> K;
        int available = N - X;
        if(K - (X%K) <= available) cout << min(X%K, K - (X%K)) << endl;
        else cout <<  (X%K) << endl;
        


    }  
    return 0;
}