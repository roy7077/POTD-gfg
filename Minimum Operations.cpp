/*-------😎➡️ ALL  POSSIBLE  APPROACHES ⬇️----------*/

/*---------------RECURSION -> TLE---------------*/
class Solution
{
    public:
    int help(int i,int n)
    {
        //base case
        if(i==n)
        return 0;
        
        if(i>n)
        return 1e9;
        
        //recursive calls
        int a=1+help(i+1,n);
        int b=1+help(i*2,n);
        
        return min(a,b);
    }
    int minOperation(int n)
    {
        return 1+help(1,n);
    }
};

/*----------------MEMOIZATION -> TLE--------------*/
class Solution
{
    public:
    int help(int i,int n,vector<int>& memo)
    {
        //base case
        if(i==n)
        return 0;
        
        if(i>n)
        return 1e9;
        
        if(memo[i]!=-1)
        return memo[i];
        
        //recursive calls
        int a=1+help(i+1,n,memo);
        int b=1+help(i*2,n,memo);
        
        return memo[i]=min(a,b);
    }
    int minOperation(int n)
    {
        vector<int> memo(1e6,-1);
        return 1+help(1,n,memo);
    }
};

/*---------------TABULATION - ✅-----------*/
// Time complexity - O(N)
// Space complexity- O(N)
class Solution
{
    public:
    int minOperation(int n)
    {
        vector<int> dp(n+1,0);
        dp[n]=0;
        for(int i=n-1;i>=0;i--)
        {
            if(i==0)
            {
                dp[0]=1+dp[i+1];
                continue;
            }
        
            int a=1+dp[i+1];
            int b=1e9;
            if(i*2<=n)
            b=1+dp[i*2];
            
            dp[i]=min(a,b);
        }
        
        return dp[0];
    }
};

/*----------------OPTIMIZED / ITERATIVE -> ✅*------------------*/

// Time complexity - O(LogN)
// Space complexity- O(1)
class Solution
{
    public:
    int minOperation(int n)
    {
        int ans=0;
        while(n)
        {
            if(!(n%2))
            n/=2;
            else
            n--;
            
            ans++;
        }
        return ans;
    }
};