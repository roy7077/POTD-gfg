// Recursion
// TLE
int mod=1e9+7;
class Solution
{
    public:
    int help(int n)
    {
        //base case
        if(n<=2)
        return 1;
        
        //recursive calls
        //small calculation
        int a=help(n-2);
        int b=help(n-3);
        
        return ((long long)a+b)%mod;
    }
    int padovanSequence(int n)
    {
       return help(n);
    }
};

// Memoization
int mod=1e9+7;
class Solution
{
    public:
    int help(int n,vector<int>& memo)
    {
        //base case
        if(n<=2)
        return 1;
        
        //memo check
        if(memo[n]!=-1)
        return memo[n];
        
        //recursive calls
        //small calculation
        int a=help(n-2,memo);
        int b=help(n-3,memo);
        
        return memo[n]=((long long)a+b)%mod;
    }
    int padovanSequence(int n)
    {
       vector<int> memo(n+1,-1);
       return help(n,memo);
    }
};


// Tabulation
int mod=1e9+7;
class Solution
{
    public:
    int padovanSequence(int n)
    {
       vector<int> dp(n+1,-1);
       dp[0]=dp[1]=dp[2]=1;
       for(int i=3;i<=n;i++)
       dp[i]=((long long)dp[i-2]+dp[i-3])%mod;
           
       return dp[n];
    }
};



// Time complexity - O(N)
// Space complexity- O(1)
int mod=1e9+7;
class Solution
{
    public:
    int padovanSequence(int n)
    {
       int a=1;
       int b=1;
       int c=1;
       
       if(n<=2)
       return 1;
       
       for(int i=3;i<=n;i++)
       {
           int temp=((long long)a+b)%mod;
           a=b;
           b=c;
           c=temp;
       }
       return c;
    }
};
