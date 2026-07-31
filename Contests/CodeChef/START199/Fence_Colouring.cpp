#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> arr(n);
       
        unordered_map<int, int> freq;
        
        for (int i = 0; i < n; i++)
        {
            /* code */cin >> arr[i];
            freq[arr[i]]++;
        }

        int maxFreq = 0;
        int maxFreqEle = -1;
        for (auto &it : freq) {
            if (it.second > maxFreq) {
                maxFreqEle = it.first;
                maxFreq = it.second;
            }
        }
        if(maxFreqEle == 1 || freq[1] == maxFreq)
        {
            cout << (n- maxFreq) << "\n";
        }
        else 
        {
            cout << (n- maxFreq) + 1 << "\n";
        
        }
      
        
        
    }
    return 0;
}