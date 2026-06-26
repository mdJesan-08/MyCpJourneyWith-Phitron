#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	
	while(T--)
	{
	    int N , L, R;
	    
	    cin >> N >> L >> R;
	    
	    int sumLeft = 0, sumInRange = 0, sumRight = 0;
	    
	    for(int i = 1; i <= N; i++)
	    {
	        int x;
	        cin >> x;
	        if( i < L) sumLeft += x;
	        else if( i > R) sumRight +=x;
	        else if(i >=L && i <= R) sumInRange += x;
	    }
	    
	    cout << max(sumLeft, sumRight) << "\n";
	    
	}

    return 0;

}
