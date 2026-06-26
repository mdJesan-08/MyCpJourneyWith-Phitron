#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	
	while(T--)
	{
	    int N , cur_X, cur_Y;
	    
	    cin >> N >> cur_X >> cur_Y;
	    
	    int min_dis = INT_MAX;
	    
	    while(N--)
	    {
	        int X, Y;
	        cin >> X >> Y;
	        int cur_dis = abs(cur_X - X)+ abs(cur_Y - Y);
	        
	        if(cur_dis < min_dis) min_dis = cur_dis;
	    }
	    
	    cout << min_dis  << "\n";
	    
	}

    return 0;

}
