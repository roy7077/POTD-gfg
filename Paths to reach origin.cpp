
// Recursion
// Time complexity - O(2^N)
class Solution
{
    public:
    int help(int i,int j)
    {
        //base case
        if(i==0 and j==0)
        return 1;
        
        if(i<0 or j<0)
        return 0;
        
        //recursive calls
        //and small calculation
        int a=help(i-1,j);
        int b=help(i,j-1);
        
        return (a+b);
    }
    int ways(int x, int y)
    {
        return help(x,y);
    }
};


// Memoization
int mod=1e9+7;
class Solution
{
    public:
    int help(int i,int j,vector<vector<int>>& memo)
    {
        //base case
        if(i==0 and j==0)
        return 1;
        
        if(i<0 or j<0)
        return 0;
        
        //memo check
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls
        //and small calculation
        int a=help(i-1,j,memo);
        int b=help(i,j-1,memo);
        
        return memo[i][j]=(a+b)%mod;
    }
    int ways(int x, int y)
    {
        vector<vector<int>> memo(x+1,vector<int>(y+1,-1));
        return help(x,y,memo);
    }
};


// Tabulation
int mod=1e9+7;
class Solution
{
    public:
    int ways(int x, int y)
    {
        vector<vector<int>> dp(x+1,vector<int>(y+1,0));
        dp[0][0]=1;
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                if(i==0 and j==0)
                continue;
                
                int temp=0;
                if(i-1>=0)
                temp=(temp+dp[i-1][j])%mod;
                
                if(j-1>=0)
                temp=(temp+dp[i][j-1])%mod;
                
                dp[i][j]=temp;
            }
        }
        return dp[x][y];
    }
};


// Space optimized
int mod=1e9+7;
class Solution
{
    public:
    int ways(int x, int y)
    {
        vector<int> pre(y+1,0);
        pre[0]=1;
        for(int i=0;i<=x;i++)
        {
            vector<int> curr(y+1,0);
            if(i==0)
            curr[0]=1;
            
            for(int j=0;j<=y;j++)
            {
                if(i==0 and j==0)
                continue;
                
                int temp=0;
                if(i-1>=0)
                temp=(temp+pre[j])%mod;
                
                if(j-1>=0)
                temp=(temp+curr[j-1])%mod;
                
                curr[j]=temp;
            }
            pre=curr;
        }
        return pre[y];
    }
};