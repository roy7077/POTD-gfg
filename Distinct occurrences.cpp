
// RECURSION (TLE)
class Solution
{
    public:
    int help(string& s,string& t,int i,int j)
    {
        //base case
        if(j>=t.length())
        return 1;
        
        if(i>=s.length())
        return 0;
        
        //recursive calls
        //and small calculation
        int b=0;
        int a=help(s,t,i+1,j);
        if(s[i]==t[j])
        b=help(s,t,i+1,j+1);
        
        return (a+b);
    }
    int subsequenceCount(string s, string t)
    {
       return help(s,t,0,0);
    }
};
 
// Memoization
int mod=1e9+7;
class Solution
{
    public:
    int help(string& s,string& t,int i,int j,vector<vector<int>>& memo)
    {
        //base case
        if(j>=t.length())
        return 1;
        
        if(i>=s.length())
        return 0;
        
        //memo check
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls
        //and small calculation
        int b=0;
        int a=help(s,t,i+1,j,memo);
        if(s[i]==t[j])
        b=help(s,t,i+1,j+1,memo);
        
        return memo[i][j]=(a+b)%mod;
    }
    int subsequenceCount(string s, string t)
    {
        vector<vector<int>> memo(s.length(),vector<int>(t.length(),-1));
       return help(s,t,0,0,memo);
    }
};


// Tabulation
int mod=1e9+7;
class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
        int n=s.length();
        int m=t.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
        dp[i][t.length()]=1;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                int a,b;
                a=b=0;
                
                a=dp[i+1][j];
                
                if(s[i]==t[j])
                b=dp[i+1][j+1];
                
                dp[i][j]=(a+b)%mod;
            }
        }
        
        return dp[0][0];
    }
};


// Space optimized
int mod=1e9+7;
class Solution
{
    public:
    int subsequenceCount(string s, string t)
    {
        int n=s.length();
        int m=t.length();
        vector<int> next(m+1,0);
        next[m]=1;
        
        for(int i=n-1;i>=0;i--)
        {
            vector<int> curr(m+1,0);
            curr[m]=1;
            for(int j=0;j<m;j++)
            {
                int a,b;
                a=b=0;
                
                a=next[j];
                
                if(s[i]==t[j])
                b=next[j+1];
                
                curr[j]=(a+b)%mod;
            }
            next=curr;
        }
        
        return next[0];
    }
};