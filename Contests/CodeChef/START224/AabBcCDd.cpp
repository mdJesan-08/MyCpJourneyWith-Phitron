#include<bits/stdc++.h>
using namespace std;

char bigtoSmall(char ch)
{
    if(ch >= 'a' && ch < 'z') return ch;

    else return 'a' + (ch - 'A');
  
}
int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int length;
        cin >> length;
        string s;
        cin >> s;
        int hashArr[123] = {0};
        // int has_arr_t[123] = {0};
        for(int i = 0; i < s.length(); i++)
        {
          
           s[i] = bigtoSmall(s[i]);
           hashArr[s[i]] += 1;
            // has_arr_t[t[i]] += 1;
        }
        // for(char ch = 'a'; ch <= 'z'; ch++)
        // {
        //     if( hashArr[ch]  != 0 )cout << hashArr[ch] << " ";
        // }
        sort(hashArr,  hashArr + 123);
        int max = hashArr[122];
        int sMax = hashArr[121];
        cout << max + sMax << endl;

    }
      
    return 0;
}
