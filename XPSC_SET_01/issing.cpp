#include <bits/stdc++.h>
using namespace std;

int main() {
  
    long long int N;
    cin >> N;
    vector<long long int> arr(N-1);
    for(int i = 0; i < N-1; i++) cin >> arr[i];

    long long int  sum = 0;

    for(long long int i = 0; i < N-1 ; i++)
    {
        sum += arr[i];
    }

    cout << (N*(N+1)/2) - sum;
    return 0;
}