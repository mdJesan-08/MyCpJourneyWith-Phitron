#include <bits/stdc++.h>
using namespace std;

using ll = long long;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    
    while (t--) 
    {
       int n; cin >> n;
       vector<int> arr(n);
       
       for (int i = 0; i < n; i++) cin >> arr[i];

       int s = 0, e = arr.size()-1;
       
       bool isPalin = true;
       int trialOneMid , trialTwoMid;

        while(s <= e)
        {

            if(arr[s] != arr[e])
            {
                // check gap 
                int gap = abs(arr[s] - arr[e]);
                if(gap == 2)
                {
                    trialOneMid = (arr[s] + arr[e])/2;
                    trialTwoMid = trialOneMid -1;
                    break;
                }
                else {isPalin = false; break;}
            }
            s++; e--;
        }
        int tem_s = s, tem_e = e;
        // already a plaindrome
        if(s > e) cout << "Yes" << endl;
        else if(!isPalin) cout << "No" << endl;
        else
        {
            // trial 1 
            while(s <= e)
            {

                if(arr[s] != arr[e])
                {
                    // check gap 
                    int gap = abs(arr[s] - arr[e]);
                    if(gap == 2)
                    {
                        int curMid = (arr[s] + arr[e])/2;
                        int curTwoMid = curMid-1;
                        if(!(trialOneMid == curMid || trialOneMid == curTwoMid)) {isPalin = false ; break;}
                    }
                    else {isPalin = false; break;}
                }
                s++; e--;
            }

            if(isPalin) {cout << "Yes" << endl;}
            else
            {
                isPalin = true;
                s = tem_s; e = tem_e;
                while(s <= e)
                {

                    if(arr[s] != arr[e])
                    {
                        // check gap 
                        int gap = abs(arr[s] - arr[e]);
                        if(gap == 2)
                        {
                            int curMid = (arr[s] + arr[e])/2;
                            int curTwoMid = curMid-1;
                            if(!(trialTwoMid == curMid || trialTwoMid == curTwoMid)) {isPalin = false ; break;}
                        }
                        else {isPalin = false; break;}
                    }
                    s++; e--;
                }
                if(isPalin) {cout << "Yes" << endl;}
                else {cout << "No" << endl;}
            }



        }


        
    }
    return 0;
}