// 😎 GET  ALL  FOUR APPROACHES 😎

// RECURSION 
// Time complexity - O(Exponential)
// Space complexity -O(max(n,m))

class Solution
{
    public:
    
    int help(string& s1,int i,string& s2,int j)
    {
        //base case
        if(i<0 or j<0)
        return 0;
        
        //recursive calls
        //small calculation
        if(s1[i]==s2[j])
        return 1+help(s1,i-1,s2,j-1);
        
        int a=help(s1,i-1,s2,j);
        int b=help(s1,i,s2,j-1);
        
        return max(a,b);
    }
    int lcs(int n, int m, string s1, string s2)
    {
        return help(s1,n-1,s2,m-1);
    }
};
 

// MEMOIZATION
// Tme complexity - O(n*m)
// Space complexity -O(max(n,m)+(n*m))

class Solution
{
    public:
    
    int help(string& s1,int i,string& s2,int j,vector<vector<int>>& memo)
    {
        //base case
        if(i<0 or j<0)
        return 0;
        
        //memo check - is ans already calculated
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls
        //small calculation
        if(s1[i]==s2[j])
        return memo[i][j]=1+help(s1,i-1,s2,j-1,memo);
        
        int a=help(s1,i-1,s2,j,memo);
        int b=help(s1,i,s2,j-1,memo);
        
        return memo[i][j]=max(a,b);
    }
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
        return help(s1,n-1,s2,m-1,memo);
    }
};
 

// TABULATION
// Time complexity - O(n*m)
// Space complexity -O(n*m)

 

class Solution
{
    public:
    
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    continue;
                }
                
                int a=dp[i-1][j];
                int b=dp[i][j-1];
                
                dp[i][j]=max(a,b);
            }
        }
        
        return dp[n][m];
    }
};
SPACE OPTIMIZED

Time complexity - O(n*m)

Space complexity -O(m+m)

class Solution
{
    public:
    
    int lcs(int n, int m, string s1, string s2)
    {
        vector<int> pre(m+1,0);
        
        for(int i=1;i<=n;i++)
        {
            vector<int> curr(m+1,0);
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                {
                    curr[j]=1+pre[j-1];
                    continue;
                }
                
                int a=pre[j];
                int b=curr[j-1];
                
                curr[j]=max(a,b);
            }
            pre=curr;
        }
        
        return pre[m];
    }
};