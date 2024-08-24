// Memoization
class Solution {
    public:
    int help(vector<int>& wt,vector<int>& val,int i,int W,vector<vector<int>>& memo)
    {
        // base case
        if(i>=wt.size())
        return 0;
        
        // memo check
        if(memo[i][W]!=-1)
        return memo[i][W];
        
        // recursive calls
        // and small calculation
        // take & notTake
        int a=help(wt,val,i+1,W,memo);
        int b=0;
        if(wt[i]<=W)
        b=val[i]+help(wt,val,i+1,W-wt[i],memo);
        
        return memo[i][W]=max(a,b);
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n=val.size();
        vector<vector<int>> memo(n,vector<int>(W+1,-1));
        return help(wt,val,0,W,memo);
    }
};

// Tabulation
class Solution {
    public:
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n=val.size();
        vector<vector<int>> dp(n+1,vector<int>(W+1,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=W;j++)
            {
                // take & notTake
                int a=dp[i+1][j];
                int b=0;
                if(j>=wt[i])
                b=val[i]+dp[i+1][j-wt[i]];
                
                dp[i][j]=max(a,b);
            }
        }
        
        return dp[0][W];
    }
};


// Space optimization
class Solution {
    public:
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n=val.size();
        vector<int> next(W+1,0);
        for(int i=n-1;i>=0;i--)
        {
            vector<int> curr(W+1,0);
            for(int j=0;j<=W;j++)
            {
                // take & notTake
                int a=next[j];
                int b=0;
                if(j>=wt[i])
                b=val[i]+next[j-wt[i]];
                
                curr[j]=max(a,b);
            }
            next=curr;
        }
        
        return next[W];
    }
};

