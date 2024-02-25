//Don't use vector for memorization, if you use you will definitely get TLE, 
//use array and memset to avoid TLE.
// Memoization
#define ll long long int
class Solution
{
    public:
    ll help(ll n,int* v,int i,ll memo[][3])
    {
        //base case
        if(n==0)
        return 1;
        
        if(n<0 or i<0)
        return 0;
        
        //memo check
        if(memo[n][i]!=-1)
        return memo[n][i];
        
        //recursive call
        //and small calculation
        ll take=help(n-v[i],v,i,memo);
        ll skip=help(n,v,i-1,memo);
        
        return memo[n][i]=(take+skip);
    }
    long long int count(long long int n)
    {
        int v[3]={3,5,10};
        ll memo[n+1][3];
        memset(memo,-1,sizeof(memo));
        
        return help(n,v,2,memo);
    }
};

// Tabulation
#define ll long long int
class Solution
{
    public:
    long long int count(long long int n)
    {
        int v[3]={3,5,10};
        ll dp[n+1][3];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<3;i++)
        dp[0][i]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<3;j++)
            {
                ll take,skip;
                take=skip=0;
                
                if((i-v[j])>=0)
                take=dp[i-v[j]][j];
                
                if(j!=0)
                skip=dp[i][j-1];
                
                dp[i][j]=(skip+take);
            }
        }
        return dp[n][2];
    }
};