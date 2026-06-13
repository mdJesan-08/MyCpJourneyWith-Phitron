#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int A, B;
    cin >> A >> B;
    int first_max = max(A,B);

    if(first_max == A ) cout << first_max + max(first_max-1, B);
    else cout << first_max + max(first_max-1, A);


    return 0;
}