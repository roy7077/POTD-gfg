// User function Template for C++

int mod=1e9+7;
#define ll long long

class Solution{

public:
     
    int ncr_dp(int n,int r,vector<vector<ll>>& memo)
    {
        //base case
        if(r>n)
        return 0;
        
        if(r==n or r==0)
        return 1;
        
        if(r==1)
        return n;
        
        //memo check
        if(memo[n][r]!=-1)
        return memo[n][r];
        
        //recursive calls and small calculations
        ll a=ncr_dp(n-1,r,memo);
        ll b=ncr_dp(n-1,r-1,memo);
        
        return memo[n][r]=(a+b)%mod;
    }
    int nCr(int n, int r){
        
        
        vector<vector<ll>> memo(n+1,vector<ll>(r+1,0));
        // int ans=ncr_dp(n,r,memo);
        
        for(int i=1;i<n+1;i++)
        {
            for(int j=0;j<r+1;j++)
            {
                if(j==i or j==0)
                {
                    memo[i][j]=1;
                    continue;
                }
                
                if(j==1)
                {
                    memo[i][j]=i;
                    continue;
                }
                
                if(j>i)
                {
                    memo[i][j]=0;
                    continue;
                }
                
                ll a=memo[i-1][j-1];
                ll b=memo[i-1][j];
                
                memo[i][j]=(a+b)%mod;
            }
        }
        
        
        
        return memo[n][r];
    
    }
};

