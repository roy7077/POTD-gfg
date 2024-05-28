// Recursion
// TLE
class Solution {
    public:
    int help(vector<int>& cost,int i,int w)
    {
        //base case
        if(i>=cost.size())
        {
            if(w)
            return 1e9;
            else
            return 0;
        }
        
        if(w==0)
        return 0;
        
        //recursive calls
        //and small calculation
        
        int a=1e9;
        int b=1e9;
        
        //dont take
        a=help(cost,i+1,w);
        
        if((i+1)<=w and cost[i]!=-1)
        b=cost[i]+help(cost,i,w-(i+1));
        
        return min(a,b);
    }
    int minimumCost(int n, int w, vector<int> &cost) {
        return help(cost,0,w);
    }
};




// Memoization
class Solution {
    public:
    int help(vector<int>& cost,int i,int w,vector<vector<int>>& memo)
    {
        //base case
        if(i>=cost.size())
        {
            if(w)
            return 1e9;
            else
            return 0;
        }
        
        if(w==0)
        return 0;
        
        //memo check
        if(memo[i][w]!=-1)
        return memo[i][w];
        
        //recursive calls
        //and small calculation
        
        int a=1e9;
        int b=1e9;
        
        //dont take
        a=help(cost,i+1,w,memo);
        
        if((i+1)<=w and cost[i]!=-1)
        b=cost[i]+help(cost,i,w-(i+1),memo);
        
        return memo[i][w]=min(a,b);
    }
    int minimumCost(int n, int w, vector<int> &cost) {
        vector<vector<int>> memo(n,vector<int>(w+1,-1));
        int ans=help(cost,0,w,memo);
        return ans>=1e9 ? -1 : ans;
    }
};





// Tabulation
class Solution {
    public:
    int minimumCost(int n, int w, vector<int> &cost) {
        vector<vector<int>> dp(n+1,vector<int>(w+1,1e9));
        for(int i=0;i<=n;i++)
        dp[i][0]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=w;j++)
            {
                int a=dp[i+1][j];
                
                int b=1e9;
                if((i+1)<=j and cost[i]!=-1)
                b=cost[i]+dp[i][j-(i+1)];
                
                dp[i][j]=min(a,b);
            }
        }
        
        return dp[0][w]>=1e9 ? -1:dp[0][w];
    }
};






// Optimized space
class Solution {
    public:
    int minimumCost(int n, int w, vector<int> &cost) {
        vector<int> next(w+1,1e9);
        next[0]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            vector<int> curr(w+1,1e9);
            curr[0]=0;
            for(int j=0;j<=w;j++)
            {
                int a=next[j];
                
                int b=1e9;
                if((i+1)<=j and cost[i]!=-1)
                b=cost[i]+curr[j-(i+1)];
                
                curr[j]=min(a,b);
            }
            next=curr;
        }
        
        return next[w]>=1e9 ? -1:next[w];
    }
};


