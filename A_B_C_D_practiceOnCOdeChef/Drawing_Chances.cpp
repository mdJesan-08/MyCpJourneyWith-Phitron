#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	
	while(T--)
	{
	    int N, M;
	    cin >> N >> M;
	    
	    string s;
	    cin >> s;
	    
	    int A_wins = 0, B_wins = 0;
	    
	    for(int i = 0; i < M; i++)
	    {
            if(s[i] == '1') A_wins++;
            else B_wins++;
	    }

        if(A_wins == B_wins) 
        {
            if(N == M) cout << "YES" << "\n";
            else 
            {
                int remainMatch = N - M;
                if(remainMatch % 2 == 0 ) cout << "YES" << "\n";
                else cout << "NO" << "\n";
            }

        }
        else
        {
            int compensate  = abs(A_wins - B_wins);

            if(N-M >=compensate)
            {
                if(N-M == compensate) cout << "YES" << "\n";
                else
                {
                    int afterCompensate = (N- M) - compensate;
                    if(afterCompensate % 2 == 0) cout << "YES" << "\n";
                    else cout << "NO" << "\n";
                }
            }
            else cout << "NO" << "\n";
        }

        
	}

}
