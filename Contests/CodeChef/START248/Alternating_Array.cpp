#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int t; cin >> t;
	while(t--)
	{
	    int n; cin >> n;
        vector<int> arr(n);

	    char expected;
        int minCnt_1 = 0;


        // trail  1
	    for(int i = 0; i < n; i++)
	    {
	        int x;
	        cin >> x;
            arr[i]  = x;
	        if(i == 0)
	        {
	            if(x%2 == 0) expected = 'o';
                else expected = 'e';
	        }
            else
            {
                if(expected == 'e')
                {
                    if(x%2 != 0) minCnt_1++;
                    expected = 'o';
                }
                else if(expected == 'o')
                {
                    if(x%2 == 0) minCnt_1++;
                    expected = 'e';
                }
            }

        }

        reverse(arr.begin(), arr.end());

       // trail 2 
        int minCnt_2 = 0;
	    for(int i = 0; i < n; i++)
	    {

	        if(i == 0)
	        {
	            if(arr[i]%2 == 0) expected = 'o';
                else expected = 'e';
	        }
            else
            {
                if(expected == 'e')
                {
                    if(arr[i]%2 != 0) minCnt_2++;
                    expected = 'o';
                }
                else if(expected == 'o')
                {
                    if(arr[i]%2 == 0) minCnt_2++;
                    expected = 'e';
                }
            }

        }

        cout << min(minCnt_1,minCnt_2) << endl;
	}
	
	return 0;

}
