#include <bits/stdc++.h>
using namespace std;

int main() {
  
    long long int N;
    cin >> N;

    vector<long long> arr(N);
    long long int sum = 0;

    unordered_map<int, int> map;


    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        map[arr[i]]++;

        sum += arr[i];
    }

    // case 1
    if(sum == 0)
    {
       cout << "0";
       return 0;
    } 

    // case 2 for -1 besi
    if(map[-1] > map[1])
    {
        long long int dif = (map[-1]- map[1]);
        if( dif %2 == 0) cout << dif /2;
        else cout << (dif / 2 ) + 1;
    }
    // cout << map[-1] << " " << map[1];


    // case 3 for 1 besi
    if(map[1] > map[-1])
    {
        long long int dif = (map[1]- map[-1]);
        if( dif %2 == 0) cout << dif /2;
        else cout << (dif / 2 ) + 1;
    }
    
    
    
    return 0;
}