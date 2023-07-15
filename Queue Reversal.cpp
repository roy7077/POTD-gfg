class Solution
{
    public:
    
    void help(queue<int>& q)
    {
        //base case
        if(q.empty())
        return ;
        
        //recursive call 
        //small calculation
        
        int temp=q.front();
        q.pop();
        help(q);
        q.push(temp);
    }
    queue<int> rev(queue<int> q)
    {
        help(q);
        return q;
    }
};
