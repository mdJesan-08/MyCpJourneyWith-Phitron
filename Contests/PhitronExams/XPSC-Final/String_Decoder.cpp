#include <bits/stdc++.h>
using namespace std;

int main() {
    
    long long int T;
    cin >> T;


    while (T--)
    {
    //   cout << s << endl;
      string s;
      cin >> s;
      
      string result = "";

      for(int i = 0; i < s.size(); i= i+2)
      {
        char target = s[i];
        int repeatNo = s[i+1] -48;
        for(int j = 0; j < repeatNo; j++)
        {
            result += target;
        }
      }
      cout << result << endl;
    }
    
  
    
    return 0;
}