#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	
	while(t--)
	{
	    int k , n;
	    cin >> n >> k;

        vector<int> arr(n);

        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end(), greater<int>());
        int sum = 0;

        for(int i = 0; i < k; i++) sum+= arr[i];

        cout << sum << "\n";


	}

    return 0;

}
