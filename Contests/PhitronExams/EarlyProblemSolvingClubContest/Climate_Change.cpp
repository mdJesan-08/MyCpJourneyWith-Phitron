#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;
    long long int  arr[size];
    long long int preSum[size]; 
    long long int sum = 0;
    for(int i = 0; i < size; i++)
    {
        long long int val ;
        cin >> val;
        sum += val;
        preSum[i] = sum;
        arr[i] = val;
    }
    int cnt = 0;
    for(int i = 0; i < size-1; i++)
    {
        if( (sum - preSum[i]) == preSum[i] ) cnt++;
    }

    cout << cnt;
 
    return 0;
}