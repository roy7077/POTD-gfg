// 😎  ALL  FOUR  APPROACHES 🔥

// RECURSION

#define ll long long
#define mod 1000000007
class Solution
{
    public:
    
    ll help(ll n)
    {
        //base case
        if(n==0)
        return 1;
        
        if(n<0)
        return 0;
        
        //recursive calls
        //small calculation
        
        ll a=help(n-1);
        ll b=help(n-2);
        ll c=help(n-3);
        
        return (((a+b)%mod)+c)%mod;
    }
    long long countWays(int n)
    {
        
        return help(n);
        
    }
};
 

// MEMOIZATION

#define ll long long
#define mod 1000000007
class Solution
{
    public:
    
    ll help(ll n,vector<ll>& memo)
    {
        //base case
        if(n==0)
        return 1;
        
        if(n<0)
        return 0;
        
        //memo check
        if(memo[n]!=-1)
        return memo[n];
        
        //recursive calls
        //small calculation
        
        ll a=help(n-1,memo);
        ll b=help(n-2,memo);
        ll c=help(n-3,memo);
        
        return memo[n]=(((a+b)%mod)+c)%mod;
    }
    long long countWays(int n)
    {
        vector<ll> memo(n+1,-1);
        return help(n,memo);
        
    }
};
 

// TABULATION

#define ll long long
#define mod 1000000007
class Solution
{
    public:
    long long countWays(int n)
    {
        vector<ll> dp(n+1,0);
        
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            ll a,b,c;
            a=b=c=0;
            
            if(i-1>=0)
            a=dp[i-1];
            
            if(i-2>=0)
            b=dp[i-2];
            
            if(i-3>=0)
            c=dp[i-3];
            
            dp[i]=(((a+b)%mod)+c)%mod;
        }
        
        return dp[n];
    }
};
 

// SPACE  OPTIMIZED

#define ll long long
#define mod 1000000007
class Solution
{
    public:
    long long countWays(int n)
    {
        ll first=0;
        ll second=0;
        ll third=1;
        
        for(int i=1;i<=n;i++)
        {
            ll a,b,c;
            a=b=c=0;
            
            if(i-1>=0)
            a=third;
            
            if(i-2>=0)
            b=second;
            
            if(i-3>=0)
            c=first;
            
            ll curr=(((a+b)%mod)+c)%mod;
            first=second;
            second=third;
            third=curr;
        }
        
        return third;
    }
};