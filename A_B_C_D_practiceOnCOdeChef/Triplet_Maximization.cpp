#include <bits/stdc++.h>
using namespace std;

int main() {
  
    int t;
    cin >> t;
    while(t--)
    {
        int x , y;

        cin >> x >> y;
        int sum = 0;

        if( x == 0)
        {
            // rest of them is 2
            sum += ((y/3) * 2);
            cout << sum << "\n";
            continue;
            
        }

        else if( y == 0)
        {
            // rest of them is 2
            sum += ((x/3) * 1);
            cout << sum << "\n";
            continue;
            
        }

        else
        {
           int posi_pair = x/ 2;

           if(y > posi_pair)
           {
            // two dominating 
            int paired = (x/2);
            int total_left_over = (y - (x/2)) + x%2;

            cout << (paired*2) + (total_left_over / 3)*2 << "\n";
           }

           else
           {
                // one dominating 
                int paired = y;
                int total_left_over = ((x/2) - y)*2 + x%2;

                cout << paired * 2 + (total_left_over / 3)*1<< "\n"; 
           }

        }
    }
    return 0;
}