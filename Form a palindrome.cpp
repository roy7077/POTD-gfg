
// Memoization
class Solution{
  public:
    
    int memoization(string& s1,string& s2,int i,int j,vector<vector<int>>& memo)
    {
        //base case
        if(i<0 or j<0)
        return 0;
        
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        if(s1[i]==s2[j])
        return memo[i][j]=1+memoization(s1,s2,i-1,j-1,memo);
        
        int a=memoization(s1,s2,i-1,j,memo);
        int b=memoization(s1,s2,i,j-1,memo);
        
        return memo[i][j]=max(a,b);
    }
    
    int countMin(string str)
    {
        string s1=str;
        reverse(str.begin(), str.end());
        vector<vector<int>> memo(str.length(),vector<int>(str.length(),-1));
        
        int len=memoization(s1,str,str.length()-1,str.length()-1,memo);
        return str.length()-len;
    }
};


// Tabulation
class Solution{
  public:
    
    int countMin(string str)
    {
        string s1=str;
        reverse(str.begin(), str.end());
        int n=str.length();
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==str[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                {
                    int a=dp[i-1][j];
                    int b=dp[i][j-1];
                    
                    dp[i][j]=max(a,b);
                }
            }
        }
        
        return n-dp[n][n];
    }
};


// Space optimized
class Solution{
  public:
    
    int countMin(string str)
    {
        string s1=str;
        reverse(str.begin(), str.end());
        int n=str.length();
        vector<int> pre(n+1,0);
        
        for(int i=1;i<=n;i++)
        {
            vector<int> curr(n+1);
            for(int j=1;j<=n;j++)
            {
                if(s1[i-1]==str[j-1])
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
        
        return n-pre[n];
    }
};
