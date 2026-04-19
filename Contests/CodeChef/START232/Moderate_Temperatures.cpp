#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--)
	{
	    int N;
        cin >> N;
	    vector<int> arr(N);
	    int maxi = INT_MIN, mini = INT_MAX;
	    for(int i = 0; i < N; i++)
	    {
	        cin >> arr[i];
            maxi = max(maxi,arr[i]);
            mini = min(mini,arr[i]);
	    }
        // cout << maxi << " " << mini << endl;

        int cnt = 0;
        for(int i = 0; i < N; i++)
        {
            if(arr[i] > mini && arr[i] < maxi) cnt++;
        }
        cout << cnt << endl;
	}

}
