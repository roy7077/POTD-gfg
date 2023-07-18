// 😎  GET  ALL  APPROACHES  😎

// RECURSION

class Solution{
  public:
  
    int help(string& s1,string& s2,int i,int j)
    {
        //base case
        if(i<0 or j<0)
        return 0;
        
        //recursive calls
        //small calculation
        
        if(s1[i]==s2[j])
        return 1+help(s1,s2,i-1,j-1);
        else
        {
            int a=help(s1,s2,i-1,j);
            int b=help(s1,s2,i,j-1);
            return max(a,b);
        }
        
    }
    int longestPalinSubseq(string A) {
        
        string B=A;
        reverse(B.begin(),B.end());
        int n=A.length();
        
        return help(A,B,n-1,n-1);
    }
};
 

// MEMOIZATION

class Solution{
  public:
  
    int help(string& s1,string& s2,int i,int j,vector<vector<int>>& memo)
    {
        //base case
        if(i<0 or j<0)
        return 0;
        
        //memo check - is ans already calculated
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls
        //small calculation
        
        if(s1[i]==s2[j])
        return memo[i][j]=1+help(s1,s2,i-1,j-1,memo);
        else
        {
            int a=help(s1,s2,i-1,j,memo);
            int b=help(s1,s2,i,j-1,memo);
            return memo[i][j]=max(a,b);
        }
        
    }
    int longestPalinSubseq(string A) {
        
        string B=A;
        reverse(B.begin(),B.end());
        int n=A.length();
        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));
        return help(A,B,n-1,n-1,memo);
    }
};
 

// TABULATION

class Solution{
  public:
  
    int longestPalinSubseq(string A) {
        
        string B=A;
        reverse(B.begin(),B.end());
        int n=A.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(A[i-1]==B[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                {
                    int a=dp[i-1][j];
                    int b=dp[i][j-1];
                    
                    dp[i][j]=max(a,b);
                }
            }
        }
        
        return dp[n][n];
    }
};
 

// SPACE OPTIMIZED

class Solution{
  public:
  
    int longestPalinSubseq(string A) {
        
        string B=A;
        reverse(B.begin(),B.end());
        int n=A.length();
        
        vector<int> pre(n+1,0);
        
        for(int i=1;i<=n;i++)
        {
            vector<int> curr(n+1,0);
            for(int j=1;j<=n;j++)
            {
                if(A[i-1]==B[j-1])
                curr[j]=1+pre[j-1];
                else
                {
                    int a=pre[j];
                    int b=curr[j-1];
                    
                    curr[j]=max(a,b);
                }
            }
            pre=curr;
        }
        
        return pre[n];
    }
};