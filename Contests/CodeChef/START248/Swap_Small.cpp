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
        vector<int> resultArr;
        int cntZeros = 0;
        for(int i = 0; i < n; i++) 
        {
            int x;
            cin >> x;
            if(x == 0) cntZeros++;
            else resultArr.push_back(x);
        }
        for(int i = 0; i < cntZeros; i++) cout << 0 << " ";
        for(int i = 0; i < resultArr.size(); i++) cout << resultArr[i] << " ";



        cout << endl;

        
    }
    return 0;
}