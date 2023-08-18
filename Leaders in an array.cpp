//Time  complexity - O(N)
//Space complexity - O(N)
class Solution{
    public:
    vector<int> leaders(int a[], int n){
        
        stack<int> st;
        vector<int> ans;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and st.top()<=a[i])
            st.pop();
            
            if(st.empty())
            {
                st.push(a[i]);
                ans.push_back(a[i]);
            }
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};