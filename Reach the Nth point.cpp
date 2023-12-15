
/*------------RECURSION (TLE)---------------*/
class Solution{
    public:
    int help(int n)
    {
        //base case
        if(n==0)
        return 1;
        
        if(n<0)
        return 0;
        
        //small calculation
        //recursive calls
        int a=help(n-1);
        int b=0;
        if(n-2>=0)
        b=help(n-2);
        
        return (a+b);
    }
	    
	int nthPoint(int n){
	    return help(n);
	}
};


/*----------------------------MEMOIZATION------------------*/
#define ll long long
int mod=1e9+7;
class Solution{
    public:
    int help(int n,vector<int>& memo)
    {
        //base case
        if(n==0)
        return 1;
        
        if(n<0)
        return 0;
        
        //memo check
        if(memo[n]!=-1)
        return memo[n];
        
        //small calculation
        //recursive calls
        ll a=help(n-1,memo);
        ll b=0;
        if(n-2>=0)
        b=help(n-2,memo);
        
        return memo[n]=(a+b)%mod;
    }
	    
	int nthPoint(int n){
	    
	    vector<int> memo(n+1,-1);
	    return help(n,memo);
	}
};


/*--------------------------TABULATION--------------------*/
#define ll long long
int mod=1e9+7;
class Solution{
    public:
    int nthPoint(int n){
	    vector<int> dp(n+1,-1);
	    dp[0]=1;
	    dp[1]=1;
	    for(int i=2;i<=n;i++)
	    {
	        int a=dp[i-1];
	        int b=dp[i-2];
	        dp[i]=(a+b)%mod;
	    }
	    return dp[n];
	}
};


/*----------------------------SPACE OPTIMIZED---------------------*/
#define ll long long
int mod=1e9+7;
class Solution{
    public:
    int nthPoint(int n){
        
        if(n==0 or n==1)
        return 1;
        
	    int pre2=1;
	    int pre1=1;
	    for(int i=2;i<=n;i++)
	    {
	        int curr=(pre1+pre2)%mod;
	        pre2=pre1;
	        pre1=curr;
	    }
	    return pre1;
	}
};