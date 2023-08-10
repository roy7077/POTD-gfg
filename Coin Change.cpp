// 😎 GET ALL  APPROACHES 😎

// RECURSION

#define ll long long
class Solution {
  public:
    
    ll help(int* coins,int i,int sum)
    {
        //base cases
        if(i==0)
        {
            if(sum%coins[0]==0)
            return 1;
            else
            return 0;
        }
        
        if(sum<0)
        return 0;
        
        if(sum==0)
        return 1;
        
        //recursive calls
        int a,b;
        a=b=0;
        
        a=help(coins,i-1,sum);
        
        if(sum>=coins[i])
        b=help(coins,i,sum-coins[i]);
        
        return a+b;
    }
    long long int count(int coins[], int N, int sum) {
        
        return help(coins,N-1,sum);
    }
};
 

// MEMOIZATION

#define ll long long
class Solution {
  public:
    
    ll help(int* coins,int i,int sum,vector<vector<ll>>& memo)
    {
        //base cases
        if(i==0)
        {
            if(sum%coins[0]==0)
            return 1;
            else
            return 0;
        }
        
        if(sum<0)
        return 0;
        
        if(sum==0)
        return 1;
        
        //memo check
        if(memo[i][sum]!=-1)
        return memo[i][sum];
        
        //recursive calls
        ll a,b;
        a=b=0;
        
        a=help(coins,i-1,sum,memo);
        
        if(sum>=coins[i])
        b=help(coins,i,sum-coins[i],memo);
        
        return memo[i][sum]=a+b;
    }
    long long int count(int coins[], int N, int sum) {
        
        vector<vector<ll>> memo(N+1,vector<ll>(sum+1,-1));
        return help(coins,N-1,sum,memo);
    }
};
 

// TABULATION

#define ll long long
class Solution {
  public:
    
    long long int count(int coins[], int N, int sum) {
        
        vector<vector<ll>> dp(N,vector<ll>(sum+1,0));
        for(int i=1;i<=sum;i++)
        {
            if(i%coins[0]==0)
            dp[0][i]=1;
        }
        
        for(int i=0;i<N;i++)
        dp[i][0]=1;
        
        for(int i=1;i<N;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                ll a,b;
                a=b=0;
                
                a=dp[i-1][j];
                if(j>=coins[i])
                b=dp[i][j-coins[i]];
                
                dp[i][j]=(a+b);
            }
        }
        
        return dp[N-1][sum];
    }
};
 

// SPACE  OPTIMIZED

#define ll long long
class Solution {
  public:
    
    long long int count(int coins[], int N, int sum) {
        
        vector<ll> pre(sum+1,0);
        for(int i=0;i<=sum;i++)
        {
            if(i%coins[0]==0)
            pre[i]=1;
        }
        
        for(int i=1;i<N;i++)
        {
            vector<ll> curr(sum+1,0);
            for(int j=0;j<=sum;j++)
            {
                ll a,b;
                a=b=0;
                
                a=pre[j];
                if(j>=coins[i])
                b=curr[j-coins[i]];
                
                curr[j]=(a+b);
            }
            pre=curr;
        }
        
        return pre[sum];
    }
};