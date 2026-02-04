#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
        int s_1, s_2;
        cin >> s_1 >> s_2;
        int screen_taken = 0;
        int grid_available = 0;
        if(s_2 % 2 == 0)
        {
            screen_taken += s_2 / 2 ;
            grid_available += screen_taken * (15 -8); 
        }
        else 
        {

            screen_taken += s_2 / 2 + 1;
            grid_available += (screen_taken -1) * (15 -8); 
            grid_available += (15-4); 
        }

        // cout << "Grid available " << grid_available << endl;

        if(s_1 <= grid_available)
        {
            //  cout << "screen_taken :" ;
             cout <<screen_taken << endl;
            //  cout << endl;
             continue;
        }
        else 
        {
            int extra_needed = s_1 - grid_available ;
            if(extra_needed % 15 == 0) screen_taken += extra_needed / 15;
            else   screen_taken += extra_needed / 15 + 1;

        }

        // cout << "screen_taken  :" ;
        cout << screen_taken << endl;
        // cout << endl;

    }  
    return 0;
}