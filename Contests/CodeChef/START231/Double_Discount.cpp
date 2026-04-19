#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int T;
    cin >> T;
    while(T--)
    {
        int N, K;
        cin >> N >> K;

        vector<int> costArr(N);
        vector<int> tastArr(N);

        for(int i = 0; i < N; i++)
        {
            cin >> costArr[i];
        }

        for(int i = 0; i < N; i++)
        {
            cin >> tastArr[i];
        }
    }
    
    return 0;
}