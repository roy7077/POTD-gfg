*---------ALL  POSSIBLE  APPROACHES ------------*/


/*---------------RECURSION------------------*/
class Solution{
    public:
    int help(string& s1,string& s2,int i,int j)
    {
        //base case
        if(i<0 or j<0)
        return 0;
    
        //recursive calls
        if(s1[i]==s2[j])
        return 1+help(s1,s2,i-1,j-1);
        
        int a=help(s1,s2,i-1,j);
        int b=help(s1,s2,i,j-1);
        
        return max(a,b);
    }

    int minimumNumberOfDeletions(string S) { 
        string t=S;
        reverse(t.begin(),t.end());
        int n=S.length();
        int ans=help(S,t,n-1,n-1);
        return n-ans;
    } 
};


/*------------------------MEMOIZATION------------------*/
class Solution{
    public:
    int help(string& s1,string& s2,int i,int j,vector<vector<int>>& memo)
    {
        //base case
        if(i<=0 or j<=0)
        return 0;
        
        //memo check
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls 
        //small calculation
        if(s1[i-1]==s2[j-1])
        return 1+help(s1,s2,i-1,j-1,memo);
        
        int a=help(s1,s2,i-1,j,memo);
        int b=help(s1,s2,i,j-1,memo);
        
        return memo[i][j]=max(a,b);
    }

    int minimumNumberOfDeletions(string S) { 
        
        int n=S.length();
        string t=S;
        reverse(t.begin(),t.end());
        vector<vector<int>> memo(n+1,vector<int>(n+1,-1));
        int ans=help(S,t,n,n,memo);
    
        return n-ans;
    } 
};


/*-----------------------TABULATION----------------------*/
// Time complexity - O(n*n)
//Space complexity -O(n*n)
class Solution{
    public:
    int minimumNumberOfDeletions(string S) { 
        string t=S;
        reverse(t.begin(),t.end());
        int n=S.length();
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(S[i-1]==t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                    continue;
                }
                
                int a=dp[i-1][j];
                int b=dp[i][j-1];
                
                dp[i][j]=max(a,b);
            }
        }
        
        return n-dp[n][n];
    } 
};


/*-----------------------SPACE OPTIMIZED-----------------*/
// Time complexity - O(n*n)
//Space complexity -O(n)
class Solution{
    public:
    int minimumNumberOfDeletions(string S) { 
        string t=S;
        reverse(t.begin(),t.end());
        int n=S.length();
        
        vector<int> pre(n+1,0);
        for(int i=1;i<=n;i++)
        {
            vector<int> curr(n+1,0);
            for(int j=1;j<=n;j++)
            {
                if(S[i-1]==t[j-1])
                {
                    curr[j]=1+pre[j-1];
                    continue;
                }
                
                int a=pre[j];
                int b=curr[j-1];
                
                curr[j]=max(a,b);
            }
            pre=curr;
        }
        
        return n-pre[n];
    } 
};