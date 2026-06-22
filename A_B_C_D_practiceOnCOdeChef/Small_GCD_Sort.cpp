#include <bits/stdc++.h>
using namespace std;


int main() {
  
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;

        map<int, vector<int>,  greater<int>> mp;

        for(int i = 1; i <= N; i++)
        {
            mp[gcd(i,N)].push_back(i);
        }

        for(auto it = mp.begin(); it != mp.end(); it++)
        {
            // cout << it->first << endl;

            for(auto val : it->second)
            {
                cout << val << " ";
               
            }

        }

        cout << endl;
       


    }
    return 0;
}