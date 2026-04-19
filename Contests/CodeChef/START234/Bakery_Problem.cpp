#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    cout << min(N* 100 , N*60 + K);
    
    return 0;
}