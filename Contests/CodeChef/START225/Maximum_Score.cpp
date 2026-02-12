#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        
        int n;
        cin >> n;
        vector<long long int > arrA(n);
        vector<long long int > arrB(n);

        long long int sum = 0;

        for ( int i = 0; i < n; i++) {
            cin >> arrA[i];
            sum += arrA[i];
        }

        int minDiffVal= INT_MAX;
        int minDiffIn = -1;

        for ( int i = 0; i < n; i++)
        {
            cin >> arrB[i];
            int currDiff = abs(arrB[i] - arrA[i]);
            // cout << "currDiff is "  << currDiff << " ";
            if(currDiff ==  minDiffVal)
            {
                // cout << "currDIff is " << currDiff << endl;
                if(arrB[i] > arrB[minDiffIn]) minDiffIn = i;
            }

            else if(currDiff <  minDiffVal)
            {
                minDiffVal = currDiff;
                minDiffIn = i;
            }
                
        }
        // cout << "min val is " << arrB[minDiffIn] << " " << " is at " << minDiffIn << endl;

        cout << sum - arrA[minDiffIn] + arrB[minDiffIn] << endl;
        
    }  
    return 0;
}