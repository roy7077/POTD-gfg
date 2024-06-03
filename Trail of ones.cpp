// All Possible Approaches || Recursion || Memoization || Tabulation || Space Optimized || ✅🚀


// Recursion - TLE
int mod=1e9+7;
class Solution {
    public:
    int help(int n,int flag)
    {
        //base case
        if(n==0)
        {
            if(flag>=2)
            return 1;
            else
            return 0;
        }
        
        //recursive calls
        //and small calculation
        
        int a=0;
        int b=0;
        
        if(flag==2)
        a=help(n-1,flag);
        else
        a=help(n-1,0);
        
        if(flag==0)
        b=help(n-1,1);
        else
        b=help(n-1,2);
        
        return (a+b)%mod;
    }
    int numberOfConsecutiveOnes(int n) {
        int fnCall=help(n,0);
        return fnCall;
    }
};

// Memoization
int mod=1e9+7;
class Solution {
    public:
    int help(int n,int flag,vector<vector<int>>& memo)
    {
        //base case
        if(n==0)
        {
            if(flag>=2)
            return 1;
            else
            return 0;
        }
        
        //memo check
        if(memo[n][flag]!=-1)
        return memo[n][flag];
        
        //recursive calls
        //and small calculation
        
        int a=0;
        int b=0;
        
        if(flag==2)
        a=help(n-1,flag,memo);
        else
        a=help(n-1,0,memo);
        
        if(flag==0)
        b=help(n-1,1,memo);
        else
        b=help(n-1,2,memo);
        
        return memo[n][flag]=(a+b)%mod;
    }
    int numberOfConsecutiveOnes(int n) {
        vector<vector<int>> memo(n+1,vector<int>(3,-1));
        int fnCall=help(n,0,memo);
        return fnCall;
    }
};

// Tabulation
int mod=1e9+7;
class Solution {
    public:
    int numberOfConsecutiveOnes(int n) {
        vector<vector<int>> dp(n+1,vector<int>(3,0));
        dp[0][2]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=2;j++)
            {
                int a=0;
                int b=0;
                
                if(j==2)
                a=dp[i-1][j];
                else
                a=dp[i-1][0];
                
                if(j==0)
                b=dp[i-1][1];
                else
                b=dp[i-1][2];
                
                dp[i][j]=(a+b)%mod;
            }
        }
        
        return dp[n][0];
    }
};

// Space optimized
int mod=1e9+7;
class Solution {
    public:
    int numberOfConsecutiveOnes(int n) {
        vector<int> pre(3,0);
        pre[2]=1;
        
        for(int i=1;i<=n;i++)
        {
            vector<int> curr(3,0);
            for(int j=0;j<=2;j++)
            {
                int a=0;
                int b=0;
                
                if(j==2)
                a=pre[j];
                else
                a=pre[0];
                
                if(j==0)
                b=pre[1];
                else
                b=pre[2];
                
                curr[j]=(a+b)%mod;
            }
            pre=curr;
        }
        
        return pre[0];
    }
};