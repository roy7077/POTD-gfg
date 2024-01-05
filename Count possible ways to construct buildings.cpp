/*-----ALL POSSIBLE APPROACHES------*/

//RECURSION (TLE)
#define ll long long
int mod=1e9+7;
class Solution{
	public:
	int help(int i)
	{
	    //base case
	    if(i<=0)
	    return 1;
	   
	    //recursive calls
	    int a=help(i-1);
	    int b=help(i-2);
	    return (a+b)%mod;
	}
	int TotalWays(int N)
	{
	    int ans=help(N);
	    return (1LL*ans*ans)%mod;
	}
};

// MEMOIZATION
#define ll long long
int mod=1e9+7;
class Solution{
	public:
	int help(int i,vector<int>& memo)
	{
	    //base case
	    if(i<=0)
	    return 1;
	   
	    // memo check
	    if(memo[i]!=-1)
	    return memo[i];
	    
	    //recursive calls
	    int a=help(i-1,memo);
	    int b=help(i-2,memo);
	    return memo[i]=(a+b)%mod;
	}
	int TotalWays(int N)
	{
	    vector<int> memo(N+1,-1);
	    int ans=help(N,memo);
	    return (1LL*ans*ans)%mod;
	}
};

// TABULATION
#define ll long long
int mod=1e9+7;
class Solution{
	public:
	int TotalWays(int N)
	{
	    vector<int> dp(N+1,0);
	    dp[0]=1;
	    for(int i=1;i<=N;i++)
	    {
	        int a=dp[i-1];
	        int b=1;
	        if(i-2>=0)
	        b=dp[i-2];
	        
	        dp[i]=(a+b)%mod;
	    }
	    int ans=dp[N];
	    return (1LL*ans*ans)%mod;
	}
};

// SPACE OPTIMIZED
#define ll long long
int mod=1e9+7;
class Solution{
	public:
	int TotalWays(int N)
	{
	    int a=1;
	    int b=1;
	    for(int i=1;i<=N;i++)
	    {
	        int curr=(a+b)%mod;
	        b=a;
	        a=curr;
	    }
	    return (1LL*a*a)%mod;
	}
};