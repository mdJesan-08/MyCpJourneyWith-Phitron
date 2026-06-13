#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int X,Y,K;
    cin >> X >> Y >> K;
    (abs(X-Y) <= K) ? cout << "Yes" : cout << "No";
    return 0;
}