// TWO APPROACHES || Memoization || Tabulation
// Memoization
#define ll long long
class Solution{
	public:
	int x[5]={0,-1,0,+1,0};
	int y[5]={0,0,+1,0,-1};
	ll help(ll i,ll j,ll n,vector<vector<vector<ll>>>& memo)
    {
        //base case
        if(i < 0 or j < 0 or i >= 4 or j >= 3 or (i == 3 && j != 1)) 
        return 0;
            
        if(n==1)
        return 1;
        
        //memo check
        if(memo[n][i][j]!=-1)
        return memo[n][i][j];
        
        //recursive calls
        //small calculation
        ll ans=0;
        for(int k=0;k<5;k++)
        {
            int newi=i+x[k];
            int newj=j+y[k];
            ans+=help(newi,newj,n-1,memo);
        }
        
        return memo[n][i][j]= ans;
    }
    
	long long getCount(int n)
	{
		ll ans=0;
        vector<vector<vector<ll>>> memo(n+1,vector<vector<ll>>(5,vector<ll>(5,-1)));
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<3;j++)
            ans=(ans+help(i,j,n,memo));
        }
        
        return ans;
	}
};

// Tabulation
#define ll long long
class Solution{
	public:
	int x[5]={0,-1,0,+1,0};
	int y[5]={0,0,+1,0,-1};
	void help(vector<vector<vector<ll>>>& dp)
	{
	    int n=4;
	    int m=3;
	    int limit=25;
	    
	    //base case
	    for(int i=0;i<4;i++)
	    {
	        for(int j=0;j<3;j++)
	        {
	            if((i==3 and j==0) or (i==3 and j==2))
	            continue;
	            
	            dp[i][j][1]=1;
	        }
	    }
	    
	
	    for(int l=1;l<=limit;l++)
	    {
	        for(int i=0;i<4;i++)
    	    {
    	        for(int j=0;j<3;j++)
    	        {
    	            if((i==3 and j==0) or (i==3 and j==2))
    	            continue;
    	            
    	            ll ans=0;
                    for(int k=0;k<5;k++)
                    {
                        int newi=i+x[k];
                        int newj=j+y[k];
                        
                        if(newi<n and newi>=0 and newj<m and newj>=0)
                        ans+=dp[newi][newj][l-1];
                    }
                    dp[i][j][l]+=ans;
    	        }
    	    }
	    }
	    
	}

	long long getCount(int n)
	{
	    vector<vector<vector<ll>>> dp(4,vector<vector<ll>>(3,vector<ll>(26,0)));
	    help(dp);
	    
	    ll ans=0;
	    for(int i=0;i<4;i++)
	    {
	        for(int j=0;j<3;j++)
	        ans+=dp[i][j][n];
	    }
	    return ans;
	}
};