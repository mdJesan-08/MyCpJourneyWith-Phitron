#include <bits/stdc++.h>
using namespace std;

int main() {
     string S;
     cin >> S;
     vector<int> hashArray;

     for(int i = 0 ; i < S.size(); i++)
     {
        hashArray[S[i]] +=1;
        cout << S[i] << endl;
     }
    
    for(int i = 0;i < hashArray.size(); i++)
    {
        cout << hashArray[i];
    }
    return 0;
}