
#include <stack>
class Solution
{
  public:
    string reverseEqn (string s)
        {
            stack<string> st;
            string pre="";
            for(auto it:s)
            {
                if(it>='0' and it<='9')
                pre+=it;
                else
                {
                    if(pre.length()>=1)
                    st.push(pre);
                    string temp="";
                    temp+=it;
                    st.push(temp);
                    
                    pre="";
                }
            }
            
            if(pre.length()!=0)
            st.push(pre);
            
            s.clear();
            while(!st.empty())
            {
                string ch=st.top();
                st.pop();
                s+=ch;
            }
            
            return s;
        }
};

// time complexity - O(N)
// space complexity - O(N)