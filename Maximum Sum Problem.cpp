// Recursion
class Solution
{
    public:
    int help(int n)
    {
        if(n==0)
        return 0;
        
        int sum=help(n/2)+help(n/3)+help(n/4);
        
        if(sum>=n)
        return sum;
        else
        return n;
    }
    int maxSum(int n)
    {
        return help(n);
    }
};

// Memoization
class Solution
{
    public:
    int help(int n,vector<int>& memo)
    {
        if(n==0)
        return 0;
        
        //memo check
        if(memo[n]!=-1)
        return memo[n];
        
        int sum=help(n/2,memo)+help(n/3,memo)+help(n/4,memo);
        
        return memo[n]=max(sum,n);
    }
    int maxSum(int n)
    {
        vector<int> memo(n+1,-1);
        return help(n,memo);
    }
};

// Tabulation
class Solution
{
    public:
    int maxSum(int n)
    {
        vector<int> pre(n+1,0);
        for(int i=0;i<=n;i++)
        {
            int sum=pre[i/2]+pre[i/3]+pre[i/4];
            if(sum>=i)
            pre[i]=sum;
            else
            pre[i]=i;
        }
        return pre[n];
    }
};
