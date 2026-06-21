#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int T;
    cin >> T;
    while(T--)
    {
        int milkChocoNo, darkChocoNo;
        cin >> milkChocoNo >> darkChocoNo;

        if(milkChocoNo == 1 && darkChocoNo == 1 ) cout << 1 << "\n";
        else cout << milkChocoNo + darkChocoNo << "\n";
        


    }
    return 0;
}