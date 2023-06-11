class Solution{
  public:
  
    int helper(int l,int* price,vector<int>& dp)
    {
        //base case
        if(l==0)
        return 0;
        
        if(l<0)
        return -1e9;
        
        //memo check
        if(dp[l]!=-1)
        return dp[l];
        
        //recursive call
        int maxi=0;
        for(int i=1;i<=l;i++)
        {
            int sum;
            sum=price[i-1];
            sum+=helper(l-i,price,dp);
            maxi=max(maxi,sum);
        }
        
        return dp[l]=maxi;
    }
    
    int cutRod(int price[], int n) 
    {
        int maxi=0;
        for(int i=0;i<n;i++)
        maxi=max(maxi,price[i]);
        
        vector<int> dp(100006,-1);
        
        int ans=helper(n,price,dp);
        if(ans>price[n-1])
        return ans;
        else
        return price[n-1];
    }
};
