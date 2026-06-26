#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
   int T;
   cin >> T;
   
   while(T--)
   {
       int N, K;
       cin >> N >> K;

       int sum = 0;
       int i = 1;
       
       while(1)
       {
           sum = i + K;
           if( sum > N )
           {
               cout << i << "\n";
               break;
           }
           
           else
           {
               i = i + K;
           }
       }
   }

   return 0;
}
