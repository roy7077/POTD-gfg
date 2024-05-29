// Recursion
class Solution {
    public:
    int help(int n,int x,int y,int flag)
    {
        //base case
        if(n<0)
        return 0;
        
        if(n==0)
        return 1;
        
        //recursive calls
        //and small calculation
        int a=help(n-x,x,y,(!flag));
        int b=help(n-y,x,y,(!flag));
        int c=help(n-1,x,y,(!flag));
        
        return !a and !b and !c;
    }
    int findWinner(int n, int x, int y) {
        return (!help(n,x,y,1));
    }
};



/ Memoization
class Solution {
    public:
    int help(int n,int x,int y,int flag,vector<vector<int>>& memo)
    {
        //base case
        if(n<0)
        return 0;
        
        if(n==0)
        return 1;
        
        //memo check
        if(memo[n][flag]!=-1)
        return memo[n][flag];
        
        //recursive calls
        //and small calculation
        int a=help(n-x,x,y,(!flag),memo);
        int b=help(n-y,x,y,(!flag),memo);
        int c=help(n-1,x,y,(!flag),memo);
        
        return memo[n][flag]=(!a and !b and !c);
    }
    int findWinner(int n, int x, int y) {
        vector<vector<int>> memo(n+1,vector<int>(2,-1));
        return (!help(n,x,y,1,memo));
    }
};



// Tabulation
class Solution {
    public:
    int findWinner(int n, int x, int y) {
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        dp[0][0]=dp[0][1]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<2;j++)
            {
                int a=0;
                int b=0;
                int c=0;
                
                if(i-x>=0)
                a=dp[i-x][(!j)];
                
                if(i-y>=0)
                b=dp[i-y][(!j)];
                
                c=dp[i-1][(!j)];
                
                dp[i][j]=(!a and !b and !c);
            }
        }
        
        return (!dp[n][1]);
    }
};

