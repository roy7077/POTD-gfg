
// Method - 1
// Recursion
// Time complexity - O(N)
// Space complexity- O(N)
class Solution{
    public:
    void help(stack<int>& st,int& x)
    {
        //base case
        if(st.empty())
        {
            st.push(x);
            return ;
        }
        
        //recursive calls
        //small calculation
        int temp=st.top();
        st.pop();
        help(st,x);
        st.push(temp);
    }
    stack<int> insertAtBottom(stack<int> st,int x){
        help(st,x);
        return st;
    }
};


// Method - 2
// Iterative - Stack
// Time complexity - O(N)
// Space complexity- O(N)
class Solution{
    public:
    stack<int> insertAtBottom(stack<int> st,int x){
        stack<int> newSt;
        while(!st.empty())
        {
            newSt.push(st.top());
            st.pop();
        }
        
        st.push(x);
        while(!newSt.empty())
        {
            st.push(newSt.top());
            newSt.pop();
        }
        return st;
    }
};