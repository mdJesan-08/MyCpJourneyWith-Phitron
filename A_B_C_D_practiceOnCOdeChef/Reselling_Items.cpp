#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	
	while(T--)
	{
	    int N, K;
	    cin >> N >> K;
	    vector<int> arr(N);
	    for(int i = 0; i < N; i++)
	    {
	        cin >> arr[i];
	    }

        sort(arr.begin(), arr.end(), greater<int>());
        int profit = 0;

        for(int i = 0; i < N; i++)
	    {
	        if(i < K)
            {
                if(arr[i] > 5) profit += arr[i] - 5;
            }
            else
            {
                if(arr[i] > 10) profit += arr[i] - 10;
            }
	    }

        cout << profit << "\n";

	}

}
