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
        string s;
        cin >> s;
        int i = 0;
        string withoutDuplicate = "";
        while(i < n)
        {
  
           if(i == 0)  withoutDuplicate += s[i];
           else
           {
                if(!(s[i] == s[i-1])) withoutDuplicate += s[i];
           }
           i++;
        }
        cout << withoutDuplicate << endl;
     

    }
    return 0;
}