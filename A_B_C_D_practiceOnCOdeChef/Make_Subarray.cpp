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
	    string s;
	    cin >> s;
	    
	    int first_one = -1, sec_one = -1, min_zero = 0;
	    
	    for(int i = 0; i < s.size(); i++)
	    {
	        if(s[i] == '1')
	        {
	            first_one = i;
	            break;
	        }
	    }
	    
	    for(int i = first_one+ 1; i < s.size(); i++)
	    {
	         if(s[i] == '1') sec_one = i; 
	    }

        if(first_one == -1 )
        {
            cout << 0 << "\n";
            continue;
        }

        for( int i = first_one +1 ; i < sec_one; i++)
        {
           if(s[i] == '0') min_zero += 1; 
        }

        cout << min_zero << "\n";
	    
	}

    return 0;

}
