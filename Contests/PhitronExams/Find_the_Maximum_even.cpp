#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int size ;
    cin >> size;
    vector<int> arr(size);
    long long int maxi = INT_MIN;
    for(int i = 0; i < size; i++)
    {
       long long int val;
       cin >> val;
       if(val % 2 == 0) maxi = max(maxi, val);
       arr.push_back(val);
    }
    cout << maxi;
    return 0;
}