#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int T;
    cin >> T;
    while(T--)
    {
        int N, cost;
        cin >> N >> cost;
        
        int sellNo = N-cost;

        if(cost >= N) cout << 0 << "\n";


        else 
        {
            cout << sellNo*(N+1-cost)/2 << "\n";
        }

    }
    return 0;
}