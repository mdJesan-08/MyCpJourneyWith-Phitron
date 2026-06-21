#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int T;
    cin >> T;

    while(T--)
    {
        int N;
        cin >> N;
        vector<int> arr(N);

        cin >> arr[0];
        bool odd_expected = false, even_expected = false;

        int len = 0;

        if(arr[0] % 2 == 0)
        {
            // even num expecting odd
            len ++; odd_expected = true;

        }
        else 
        {
            len++; even_expected = true;
        }

        for(int i = 1; i < N; i++)
        {
            cin >> arr[i];
            if(odd_expected)
            {
                if( arr[i] % 2 != 0)
                {
                    len++;
                    odd_expected = false;
                    even_expected = true;
                }
            }
            else if(even_expected)
            {
                if( arr[i] % 2 == 0)
                {
                    len++;
                    odd_expected = true;
                    even_expected = false;
                }
            }
        }

        cout << len << "\n";
    }
    return 0;
}