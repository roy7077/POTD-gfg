// Recursion (TLE)
class Solution {
    public:
    int help(string& s1,string& s2,int i,int j)
    {
        //base case
        if(i>=s1.length())
        {
            if(j>=s2.length())
            return 1;
            else
            return 0;
        }
        
        if(j>s2.length())
        return 1;
        
        //recursive calls
        //and small calculation
        int a=help(s1,s2,i+1,j);
        int b=0;
        if(s1[i]==s2[j])
        b=help(s1,s2,i+1,j+1);
        
        return (a+b);
    }
    int countWays(string s1, string s2) {
        return help(s1,s2,0,0);
    }
};



// Memoization
#define ll long long
int mod=1e9+7;
class Solution {
    public:
    int help(string& s1,string& s2,int i,int j,vector<vector<int>>& memo)
    {
        //base case
        if(i>=s1.length())
        {
            if(j>=s2.length())
            return 1;
            else
            return 0;
        }
        
        if(j>=s2.length())
        return 1;
        
        //memo check
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls
        //and small calculation
        ll a=help(s1,s2,i+1,j,memo);
        ll b=0;
        if(s1[i]==s2[j])
        b=help(s1,s2,i+1,j+1,memo);
        
        return memo[i][j]=(a+b)%mod;
    }
    int countWays(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> memo(n,vector<int>(m,-1));
        return help(s1,s2,0,0,memo);
    }
};



// Tabulation
#define ll long long
int mod=1e9+7;
class Solution {
    public:
    int countWays(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=0;i<=n;i++)
        dp[i][m]=1;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<m;j++)
            {
                ll a=dp[i+1][j];
                ll b=0;
                
                if(s1[i]==s2[j])
                b=dp[i+1][j+1];
                
                dp[i][j]=(a+b)%mod;
            }
        }
        return dp[0][0];
    }
};



// space optimized
#define ll long long
int mod=1e9+7;
class Solution {
    public:
    int countWays(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();

        vector<int> next(m+1,0);
        next[m]=1;
        
        for(int i=n-1;i>=0;i--)
        {
            vector<int> curr(m+1,0);
            curr[m]=1;
            
            for(int j=0;j<m;j++)
            {
                ll a=next[j];
                ll b=0;
                
                if(s1[i]==s2[j])
                b=next[j+1];
                
                curr[j]=(a+b)%mod;
            }
            next=curr;
        }
        return next[0];
    }
};