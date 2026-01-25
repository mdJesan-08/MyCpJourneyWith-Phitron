#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    // line1 
    if(n==1)
    {
        cout << 1;
        return 0;
    }
    for(int i = 1; i <= n; i++)
    {
        cout << i;
    }  
    cout << endl;
    int line_in_between = n -2;
    int end_sum = 1+n;
    int first_digit = 2;
    if(line_in_between>0)
    {
        // gap_print
        int cnt = line_in_between;
        while(cnt--)
        {
            cout << first_digit;
            int gap_no = line_in_between;
            for(int i = 0; i < gap_no; i++)
            {
                cout << " ";
            }
            cout << end_sum-first_digit << endl;
            first_digit++;
        }
    }



    // bottom line
    for(int i = n; i >=1; i--)
    {
        cout << i;
    }  
    return 0;
}