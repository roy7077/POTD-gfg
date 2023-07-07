
class Solution {
  public:
  
    int helper(vector<int>& prices,int i,int buy,vector<vector<int>>& memo)
    {
        //base case
        if(i>=prices.size())
        return 0;
        
        //memo check
        if(memo[i][buy]!=-1)
        return memo[i][buy];
        
        //recursive calls
        int profit=0;
        if(buy==0)
        {
            int a=helper(prices,i+1,buy,memo)+0;
            int b=helper(prices,i+1,1,memo)-prices[i];
            
            profit=max(a,b);
        }
        else
        {
            int a=helper(prices,i+1,buy,memo)+0;
            int b=helper(prices,i+1,0,memo)+prices[i];
            
            profit=max(a,b);
        }
        
        return memo[i][buy]=profit;
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        
        vector<vector<int>> memo(n+1,vector<int>(2,-1));
        return helper(prices,0,0,memo);
    }
};