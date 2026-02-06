#include<bits/stdc++.h>

using namespace std;

int main()
{
  
    int T;
    cin >> T;
    
    while(T--)
    {
        int N;
        cin >> N;

        vector<int> arr;

        for(int i = 0; i < N; i++)
        {
            int val;
            cin >> val;
            arr.push_back(val);
        }

        int cnt = 0;
        int max_cnt = 0;

        for(int i = 0; i < N; i++)
        {
            if(arr[i] != 0) cnt++;
            else 
            {
                max_cnt = max(cnt, max_cnt);
                cnt = 0;
            }
        }
        cout << max(cnt, max_cnt) << endl;

    }
    return 0;
}