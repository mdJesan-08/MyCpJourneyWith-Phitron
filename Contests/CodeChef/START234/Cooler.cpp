#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int T;
    cin >> T;
    while(T--)
    {
        int N , M;
        cin >> N >> M;
        int res = ((N + M+1)*(N-M)) / 2;
        cout << res << endl;
    }
    return 0;
}