#include <bits/stdc++.h>
using namespace std;

int main() {
  
    map<int, pair<int,int>> mp;
    long long int n;
    cin >> n;

    vector<long long int> arr(n);

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // for(int i = 0; i < n; i++)
    // {
    //     if(mp.find(arr[i]) != mp.end()) continue;
    //     mp[arr[i]] = {i+1, i+1};
    //     for(int j = 0; j < n; j++)
    //     {
    //         if(j == i) continue;
    //         if(arr[i] == arr[j]) mp[arr[i]].second = j+1;
    //     }
    // }

     for(int i = 0; i < n; i++)
     {
        if(mp.find(arr[i]) != mp.end()) continue;
        mp[arr[i]] = {i+1, i+1};
     }
     
    for(int i = 0; i < n; i++)
     {
        if(mp.find(arr[i]) != mp.end()) continue;
        mp[arr[i]] = {i+1, i+1};
     }

    // printing
    for(auto it : mp) 
    {
        cout << it.first << " " << it.second.first << " "
             << it.second.second << endl;
    }

    return 0;
}