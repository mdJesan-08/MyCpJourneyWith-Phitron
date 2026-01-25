#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        char open_arr[3] = {'(', '{','['};
        char close_arr[3] = {')', '}',']'};
        int i = 0;
        stack<int> st;
        st.push(s[i]);
        i++;
        while(i < s.size() || !(st.empty()) )
        {
            
            if(st.top() == '('  || st.top() == '{' || st.top() == '[' )
            {
              st.push(s[i]);;
              i++;     
            }
            else
            {
                if(s[i] == ')' && st.top()== '(') 
                {
                    st.pop();
                    i++;
                }
                else if(s[i] == '}' && st.top()== '{') 
                {
                    st.pop();
                    i++;
                }
                else if(s[i] == ']' && st.top()== '[') 
                {
                    st.pop();
                    i++;
                }
                else return false;
            }
        }
    }
};