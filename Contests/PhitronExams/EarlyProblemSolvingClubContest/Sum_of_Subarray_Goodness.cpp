#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size;
    cin >> size;
    int  arr[size];

    long long int sum = 0;
    map<int, int> freq;

    for(int i = 0; i < size; i++)
    {
        int val ;
        cin >> val;
        arr[i] = val;
        freq[i]++;
    }

    
    int curr = arr[0];



    // cout << sum % sumi;

    return 0;
}