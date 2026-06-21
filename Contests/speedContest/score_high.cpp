#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;

        int A, B, C, D;
        cin >> A >> B >> C >> D;
        cout << max( max( max(A,B), C), D)  << endl;

    }
    return 0;
}