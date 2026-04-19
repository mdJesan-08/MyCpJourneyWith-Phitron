#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int T;
    cin >> T;
    while(T--)
    {
        int N;
        cin >> N;
        if((N%2 == 0 || N%5 == 0) && (N%10 != 0)) cout<< "0" << endl;
        else
        {
            if(N % 10 == 0) cout << "2" << endl;
            else
            {
                cout << min( N%2, N%5 ) << endl;
            }
        }
    }

    
    return 0;
}