// ALL POSSIBLE APPROACHES

/*---------------Recursion-----------------*/
// Time complexity - O(e^x)
// Space complexity- O(N)
class Solution{
    public:
    int help(vector<int>& cost,int i,double total)
    {
        //base case
        if(i>=cost.size())
        return 0;
        
        //recursive calls
        //small calculation
        int a,b;
        a=b=0;
        
        a=help(cost,i+1,total);
        if(total>=cost[i])
        {
            total-=cost[i];
            total+=double(0.9*cost[i]);
            b=1+help(cost,i+1,total);
        }
        
        return max(a,b);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        int ans=help(cost,0,double(total));
        return ans;
    }
};

/*---------------MEMOIZATION-----------------*/
// Time complexity - O(N)
// Space complexity- O(N*total)
class Solution{
    public:
    int help(vector<int>& cost,int i,int total,vector<vector<int>>& memo)
    {
        //base case
        if(i>=cost.size())
        return 0;
        
        //memo check
        if(memo[i][total]!=-1)
        return memo[i][total];
        
        //recursive calls
        //small calculation
        int a,b;
        a=b=0;
        
        a=help(cost,i+1,total,memo);
        if(total>=cost[i])
        b=1+help(cost,i+1,total-cost[i]+floor(0.9*cost[i]),memo);
        
        
        return memo[i][total]=max(a,b);
    }
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> memo(n+1,vector<int>(total+1,-1));
        int ans=help(cost,0,total,memo);
        return ans;
    }
};

/*---------------TABULATION-----------------*/
// Time complexity - O(N*total)
// Space complexity- O(N*total)
class Solution{
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<vector<int>> dp(n+1,vector<int>(total+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=total;j++)
            {
                int a,b;
                a=b=0;
                
                a=dp[i+1][j];
                if(j>=cost[i])
                b=1+dp[i+1][j-cost[i]+(0.9*cost[i])];
                
                dp[i][j]=max(a,b);
            }
        }
        
        return dp[0][total];
    }
};

/*---------------SPACE OPTIMIZED-----------------*/
// Time complexity - O(N*total)
// Space complexity- O(total)
class Solution{
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        vector<int> next(total+1,0);
        for(int i=n-1;i>=0;i--)
        {
            vector<int> curr(total+1,0);
            for(int j=0;j<=total;j++)
            {
                int a,b;
                a=b=0;
                
                a=next[j];
                if(j>=cost[i])
                b=1+next[j-cost[i]+(0.9*cost[i])];
                
                curr[j]=max(a,b);
            }
            next=curr;
        }
        
        return next[total];
    }
};