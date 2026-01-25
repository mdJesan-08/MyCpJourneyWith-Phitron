#include<bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<long long int> arr;
    // taking arr
    for(int i = 0; i < N; i++)
    {
        long long int x;
        cin >> x;
        arr.push_back(x);
    }

    vector<long long int> preSum;
    preSum.push_back(0);
    preSum.push_back(0);
    int cnt = 0;
    for(int i = 1; i <= N-2 ; i++)
    {
        if( (arr[i] < arr[i-1]) && (arr[i] < arr[i+1]) )
        {
            cnt++;
        }
        preSum.push_back(cnt);
    }
    preSum.push_back(cnt);
    for(int i = 0; i < preSum.size() ; i++)
    {
       cout << preSum[i] << " ";
    }
    cout << endl;

    int Q;
    cin >> Q;
    while(Q--)
    {
        int L, R;
        cin >> L >> R;
        cout << preSum[R-1] << " " << preSum[L-1]  <<endl;
    }


    return 0;
}