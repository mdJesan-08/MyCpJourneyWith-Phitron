#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int size;
        cin >> size;
       string s;
       cin >> s;
       int hashArray[123] = {0};
       for(int i = 0; i < s.size(); i++)
       {
            hashArray[s[i]]++;
       }

       bool flag = false;

       for(int i = 0; i < s.size(); i++)
       {
        //    cout << hashArray[s[i]] << " " ;
            if(hashArray[s[i]] >=2)
            { 
                flag = true;
                cout << "Yes" << endl;
                break;
            }
       }

       if(flag == false) cout << "No" << endl;
        
    }  
    return 0;
}