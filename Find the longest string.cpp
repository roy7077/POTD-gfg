
#include <iostream>
#include <set>
#include <cstring>
#include <algorithm>
#include <vector>

class Solution
{
public:
    string longestString(vector<string> &words)
    {
        set<string> st;
        for(auto it:words)
        st.insert(it);
        
        int maxi=0;
        string ans;
        for(auto it:words)
        {
            bool flag=1;
            string temp="";
            for(auto x:it)
            {
                temp+=x;
                if(st.count(temp)==0)
                {
                    flag=0;
                    break;
                }
            }
            
            if(flag)
            {
                if(it.length()>maxi)
                {
                    maxi=it.length();
                    ans=it;
                }
                else if(it.length()==maxi and it<ans)
                ans=it;
            }
        }
        
        return ans;
    }
};

// time complexity - O(N*(size of a words))
// space complexity - O(N)