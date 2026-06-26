#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes herein
	int T;
	
	cin >> T;
	
	while(T--)
	{
	    int N;
	    cin >> N;
	    vector<int> arr(N);


	    for(int i = 0; i < N; i++)
	    {
	        cin >> arr[i];
	    }

        int primeCnt = 0;

        for(int i = 0; i < N; i++)
        {
            for(int j = i+1; j < N; j++)
            {
                int sum = arr[i] + arr[j];
                if(sum == 2 || sum == 3 || sum == 5) primeCnt++;
            }
        }

        cout << primeCnt << "\n";
	    
	}

    return 0;
	

}
