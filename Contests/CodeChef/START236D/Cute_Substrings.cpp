#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        // cout << s << endl;
        int maxiLen = 0;
        for(int i = 0; i < n ; i++)
        {
            for(int j= i; j < n ; j++)
            {   
                if((j-i)%2 == 0)
                {
                    if(!(s[j] == 'u' || s[j] == 'o')) break;
                }
                else 
                {
                    if(!(s[j] == 'w')) break;
                }
                if(max(maxiLen, j -i +1) % 2 != 0) maxiLen = max(maxiLen, j -i +1);
                
            }
        
        }
        cout << maxiLen << endl;
    }
    return 0;
}