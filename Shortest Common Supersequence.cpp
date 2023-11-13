/*---------- ALL  POSSIBLE  APPROACHES--------*/

/*--------------RECURSION (TLE)-----------*/
class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int help(string& s1,string& s2,int i,int j)
    {
        //base case
        if(i<0 and j<0)
        return 0;
        
        if(i>=0 and j>=0 and s1[i]==s2[j])
        return 1+help(s1,s2,i-1,j-1);
        
        int a,b;
        a=b=1e9;
        if(i>=0)
        a=1+help(s1,s2,i-1,j);
        
        if(j>=0)
        b=1+help(s1,s2,i,j-1);
        
        return min(a,b);
    }
    
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        int ans=help(X,Y,m-1,n-1);
        return ans;
    }
};

/*-------MEMOIZATION-----------*/
class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int help(string& s1,string& s2,int i,int j,vector<vector<int>>& memo)
    {
        //base case
        if(i<=0 and j<=0)
        return 0;
        
        //memo check
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        if(i>=1 and j>=1 and s1[i-1]==s2[j-1])
        return memo[i][j]=1+help(s1,s2,i-1,j-1,memo);
        
        int a,b;
        a=b=1e9;
        if(i>=1)
        a=1+help(s1,s2,i-1,j,memo);
        
        if(j>=1)
        b=1+help(s1,s2,i,j-1,memo);
        
        return memo[i][j]=min(a,b);
    }
    
    int shortestCommonSupersequence(string X, string Y, int m, int n)
    {
        vector<vector<int>> memo(m+2,vector<int>(n+2,-1));
        int ans=help(X,Y,m,n,memo);
        return ans;
    }
};

/*----------TABULATION--------------*/
class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s1, string s2, int m, int n)
    {
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
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
        
        return m+n-dp[m][n];
    }
};


/*------------SPACE OPTIMIZED-----------*/
class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string s1, string s2, int m, int n)
    {
        vector<int> pre(n+1,0);
        for(int i=1;i<=m;i++)
        {
            vector<int> curr(n+1,0);
            for(int j=1;j<=n;j++)
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
        
        return m+n-pre[n];
    }
};