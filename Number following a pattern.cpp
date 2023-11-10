//Time complexity - O(N)
//Space complexity- O(N+N)
class Solution{   
    public:
    string printMinNumberForPattern(string S){
        int num=1;
        string ans="";
        stack<int> st;
        for(auto it:S)
        {
            st.push(num);
            num++;
            if(it=='I')
            {
                while(!st.empty())
                {
                    int ch=st.top();
                    st.pop();
                    ans+=char(ch+48);
                }
            }
        }
        st.push(num);
        while(!st.empty())
        {
            int ch=st.top();
            st.pop();
            ans+=char(ch+48);
        }
        return ans;
    }
};
