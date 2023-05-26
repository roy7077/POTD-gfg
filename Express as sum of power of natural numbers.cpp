//User function Template for C++
#define ll long long
int mod=1e9+7;

class Solution{
    public:

    int help(int n,int x,int num,vector<vector<int>> &memo){
        
        //base cases
        if(n==0)
        return 1;
        if(num>n or n<0)
        return 0;
        
        //memo check
        if(memo[n][num]!=-1)
        return memo[n][num];
        
        //recursive calls
        //small calculation
        int temp=pow(num,x);
        return memo[n][num]=(help(n-temp,x,num+1,memo)+help(n,x,num+1,memo))%mod;
    }
    int numOfWays(int n, int x)
    {
  
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return help(n,x,1,dp);
    }
};

// time _Complexity - O(N^2)
// space _Complexityity - O(N*N)