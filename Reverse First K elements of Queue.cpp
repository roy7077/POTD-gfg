// TWO APPROACHES

//ITERATIVE
//Time complexity - O(N)
//Space complexity- O(k)
class Solution
{
    public:
    queue<int> modifyQueue(queue<int> q, int k) {
        int n=q.size()-k;
        vector<int> temp;
        while(k--)
        {
            temp.push_back(q.front());
            q.pop();
        }
        
        reverse(temp.begin(),temp.end());
        for(auto it:temp)
        q.push(it);
        
        while(n--)
        {
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};

//RECURSION
//Time complexity - O(N)
//Space complexity- O(k)
class Solution
{
    public:
    void help(queue<int>& q,int k)
    {
        //base case
        if(k==0)
        return ;
        
        //recursive calls
        //small calculation
        int temp=q.front();
        q.pop();
        help(q,k-1);
        q.push(temp);
    }
    queue<int> modifyQueue(queue<int> q, int k) {
        int n=q.size()-k;
        help(q,k);
        
        while(n--)
        {
            q.push(q.front());
            q.pop();
        }
        
        return q;
    }
};