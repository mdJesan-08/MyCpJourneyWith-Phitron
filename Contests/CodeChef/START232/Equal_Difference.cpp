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
	    // int maxi = INT_MIN, mini = INT_MAX;
	    for(int i = 0; i < N; i++)
	    {
	        cin >> arr[i];
	    }
  
        int cnt = 0;
        for(int i = 0; i < N; i++)
        {
            for(int j = i+1; j < N; j++)
            {
                // cout << arr[i] << " " << arr[j] << endl;
                if(arr[j] -arr[i] == j -i) cnt++;
            }
            

        }

        cout << cnt << endl;
	}

}
