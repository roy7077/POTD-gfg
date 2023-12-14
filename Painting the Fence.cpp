/*---------MEMOIZATION--------------------*/
#define ll long long
int mod=1e9+7;
class Solution{
    public:
    ll help(int n,int& k,vector<ll>& memo)
    {
        //base cases
        if(n==1)
        return k;
        
        if(n==2)
        return static_cast<long long>(k)*k;
        
        //memo check
        if(memo[n]!=-1)
        return memo[n];
        
        //recursive calls
        //small calculation
        ll same=(help(n-2,k,memo)*(k-1))%mod;
        ll diff=(help(n-1,k,memo)*(k-1))%mod;
        
        return memo[n]=(same+diff)%mod;
    }
    long long countWays(int n, int k){
        vector<ll> memo(n+1,-1);
        ll ans=help(n,k,memo)%mod;
        
        return ans;
    }
};


/*-------------------TABULATION------------------*/

#define ll long long
int mod=1e9+7;
class Solution{
    public:
    long long countWays(int n, int k)
    {
        ll dp[n+1];
        dp[0] = 0;
        dp[1] = k;
        dp[2] = static_cast<long long>(k)*k;
        for(int i=3;i<=n;i++)
        {
            dp[i] = ((k-1)*(dp[i-1] + dp[i-2]))%mod;
        }
        return dp[n];
    }
};


/*-------------------OPTIMIZED------------------*/
#define ll long long
int mod=1e9+7;
class Solution{
    public:
    long long countWays(int n, int k){
        
        if(n==1)
        return k;
        
        ll same=k*1;
        ll diff=(static_cast<long long>(k)*(k-1))%mod;
        ll total=(same+diff)%mod;
        
        for(int i=3;i<=n;i++)
        {
            same=diff*1;
            diff=(total*(k-1));
            total=(same+diff)%mod;
        }
        return total;
    }
};