#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
	int T;
	cin >> T;
	
	while(T--)
	{
	    int N , iniScore, sabotagedLimit ;

        cin >> N >> iniScore >> sabotagedLimit;

        int maxScore = iniScore + 100*sabotagedLimit;

        int rank = 1;
        int sabotaged = 0;
        for(int i = 0; i < N; i++)
        {
            int val;
            cin >> val;

            if(val > iniScore)
            {
                // can i do anything for u or not lets see
                if(sabotaged < sabotagedLimit)
                {
                    if(val > maxScore) sabotaged++;
                    
                }
                else
                {
                    if(val > maxScore) rank++;
                }
            }
        }

        cout << rank  << "\n";


	    
	    
	}

    return 0;

}
