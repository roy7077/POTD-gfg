// User function template for C++
class Solution {
    public:
    vector<int> bracketNumbers(string str) {
        vector<int> ans;
        stack<int> st;
        
        int cnt=1;
        for(auto& it:str)
        {
            if(it=='(')
            {
                st.push(cnt);
                ans.push_back(cnt);
                cnt++;
            }
            else if(it==')')
            {
                if(!st.empty())
                {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};
