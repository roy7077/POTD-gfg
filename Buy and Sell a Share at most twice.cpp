

//code is breaking for last test case , 
// In this approach we are using N*2*3 + Recursion stack space , 
// because of recursion stack space it is not working
// Memoization
class Solution
{
    public:
    int help(vector<int>& p,int i,int flag,int cap,vector<vector<vector<int>>>& memo)
    {
        //base case
        if(cap<=0)
        return 0;
        
        if(i>=p.size())
        return 0;
        
        //memo check
        if(memo[i][flag][cap]!=-1)
        return memo[i][flag][cap];
        
        //recursive calls
        //and small calculation
        if(flag) // -> we can sell the stock
        {
            int b=help(p,i+1,1,cap,memo);
            int a=p[i]+help(p,i+1,0,cap-1,memo);
            return memo[i][flag][cap]=max(a,b);
        }
        else // -> we can buy the stock
        {
            int a=help(p,i+1,0,cap,memo);
            int b=-p[i]+help(p,i+1,1,cap,memo);
            return memo[i][flag][cap]=max(a,b);
        }
    }
    int maxProfit(vector<int>&p){
        int n=p.size();
        vector<vector<vector<int>>> memo(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return help(p,0,0,2,memo);
    }
};

// Tabulation
class Solution
{
    public:
    int maxProfit(vector<int>&p){
        int n=p.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=0;j<=1;j++)
            {
                for(int k=1;k<=2;k++)
                {
                    if(j) // -> we can sell the stock
                    {
                        
                        int b=dp[i+1][1][k];
                        int a=p[i]+dp[i+1][0][k-1];
                        dp[i][j][k]=max(a,b);
                    }
                    else // -> we can buy the stock
                    {
                        int a=dp[i+1][0][k];
                        int b=-p[i]+dp[i+1][1][k];
                        dp[i][j][k]=max(a,b);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};
//Iterative
class Solution
{
    public:
    int maxProfit(vector<int>&price){
    int buy1 = INT_MAX;
    int buy2 = INT_MAX;
    int profit1 = 0;
    int profit2 = 0;
    for(int i = 0; i < price.size(); i++)
    {
        buy1 = min(buy1, price[i]);
        profit1 = max(profit1, price[i] - buy1);
        buy2 = min(buy2, price[i] - profit1);
        profit2 = max(profit2, price[i] - buy2);
    }
    return profit2;
   }

};