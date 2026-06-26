#include <bits/stdc++.h>
using namespace std;


bool allEqual(vector<int> arr)
{
    int N = arr.size();

    for(int i = 0; i < N - 1; i++)
    {
        if(arr[i] == arr[i + 1]) continue;
        else return false;
    }
    return true;
}

int main() {
	// your code goes here
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

        sort(arr.begin(), arr.end());
        int cnt = 0;

        bool isEqual = false;

        while(isEqual == false)
        {
            for(int i = 1; i < N  ; i++)
            {
                while(1)
                {
                    if(arr[i] <= arr[0])  break;  
                    else 
                    {
                        arr[i] = arr[i] / 2;
                        cnt++;
                    }
                }
            }

            // for(int i = 0 ; i < N  ; i++) cout << arr[i] << " ";

            // cout << endl;

            sort(arr.begin(), arr.end());

            


            

            isEqual = allEqual(arr);
        }


        cout << cnt << endl ;


	}

}
