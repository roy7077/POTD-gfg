class Solution
{
    public:
    //Function to delete middle element of a stack.
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        stack<int> st;
        int n=ceil(((double)(sizeOfStack))/2);
        
        while(n)
        {
            st.push(s.top());
            s.pop();
            n--;
        }
        
        if(sizeOfStack&1)
        st.pop();
        else
        s.pop();
        
        while(!st.empty())
        {
            s.push(st.top());
            st.pop();
        }
        
    }
};