#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        // cout << s << endl;
        int  maxiCnt = 0, cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '#') cnt++;
            else 
            {
                maxiCnt = max(cnt, maxiCnt);
                cnt = 0;
            }
            maxiCnt = max(cnt, maxiCnt);
        }

        cout << ceil(float(maxiCnt)/2) << endl;
    }
    
    return 0;
}