#include <iostream>
using namespace std;

int main() {

    long long int n;
    cin >> n; 

    while (n)
    {
        long long int rem = n % 10;
        if(rem == 7)
        {
            cout << "Lucky";
            return 0;
        }
        n = n / 10;

    }
    
    cout << "Not Lucky";
    
    return 0;
}