// Monotonic stack
// Time complexity - O(N)
// Space complexity- O(3*N)
class Solution {
    public:
    vector<int> find3Numbers(vector<int> &arr) {
        int n=arr.size();
        vector<int> pre(n,-1);
        vector<int> post(n,-1);
        
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() and st.top()>=arr[i])
            st.pop();
            
            if(st.empty())
            pre[i]=-1;
            else
            pre[i]=st.top();
            
            st.push(arr[i]);
        }
        
        while(!st.empty())
        st.pop();
        
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() and st.top()<=arr[i])
            st.pop();
            
            if(st.empty())
            post[i]=-1;
            else
            post[i]=st.top();
            
            st.push(arr[i]);
        }
        
        // cout<<pre[1]<<endl;
        // cout<<post[1]<<endl;
        
        for(int i=0;i<n;i++)
        {
            if(pre[i]!=-1 and post[i]!=-1)
            return {pre[i],arr[i],post[i]};
        }
        
        return {};
    }
};
