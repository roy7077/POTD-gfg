// Monotonic stack
// Time complexity - O(N)
// Space complexity- O(3*N)

class Solution {
    public:
    int findMaxDiff(vector<int> &arr) {
        int n=arr.size();
        vector<int> pre(n,0);
        vector<int> post(n,0);
        
        // for prefix
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and st.top()>=arr[i])
            st.pop();
            
            if(!st.empty())
            pre[i]=st.top();
            else
            pre[i]=0;
            
            st.push(arr[i]);
        }
        
        // for postfix
        while(!st.empty())
        st.pop();
        
        for(int i=arr.size()-1;i>=0;i--)
        {
            while(!st.empty() and st.top()>=arr[i])
            st.pop();
            
            if(!st.empty())
            post[i]=st.top();
            else
            post[i]=0;
            
            st.push(arr[i]);
        }
        
        // Now, it's time to
        // calculate actual ans
        int ans=0;
        for(int i=0;i<arr.size();i++)
        {
            int temp=abs(pre[i]-post[i]);
            ans=max(ans,temp);
        }
        
        return ans;
    }
};
