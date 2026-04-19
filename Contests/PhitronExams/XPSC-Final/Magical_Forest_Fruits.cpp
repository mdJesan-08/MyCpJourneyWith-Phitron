#include <bits/stdc++.h>
using namespace std;

int main() {

    long long int N , Q;
    cin >> N >> Q;

    vector<long long> arr(N);
    vector<long long> preSum(N);
    long long int sum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        preSum[i] = sum;
    }

    // for (int i = 0; i < N; i++)
    // {
    //     cout << preSum[i];
    // }
    for (int i = 0; i < Q; i++)
    {
        int L , R;
        cin >> L >> R;
        if (L -1 -1 < 0)  cout << preSum[R-1] << endl;
        else cout << preSum[R-1] - preSum[L-1-1] << endl;
       
    }
    



    
  
  
    
    return 0;
}