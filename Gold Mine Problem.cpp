/*----------------ALL  POSSIBLE  APPROACHES--------------*/

/*------------RECURSION---------------*/
class Solution{
public:
    int help(vector<vector<int>>& M,int n,int m,int i,int j)
    {
        //base case
        if(j==m-1)
        return M[i][j];
        
        //recursive calls
        int a,b,c;
        a=b=c=0;
        
        if(i-1>=0 and j<m)
        a=M[i][j]+help(M,n,m,i-1,j+1);
        
        if(i+1<n and j+1<m)
        b=M[i][j]+help(M,n,m,i+1,j+1);
        
        if(j+1<m)
        c=M[i][j]+help(M,n,m,i,j+1);
        
        return max({a,b,c});
    }
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int a=help(M,n,m,i,0);
            ans=max(a,ans);
        }
        
        return ans;
    }
};
 

/*---------------MEMOIZATION----------------*/
class Solution{
public:
    int help(vector<vector<int>>& M,int n,int m,int i,int j,vector<vector<int>>& memo)
    {
        //base case
        if(j==m-1)
        return M[i][j];
        
        //memo check
        if(memo[i][j]!=-1)
        return memo[i][j];
        
        //recursive calls
        int a,b,c;
        a=b=c=0;
        
        if(i-1>=0 and j<m)
        a=M[i][j]+help(M,n,m,i-1,j+1,memo);
        
        if(i+1<n and j+1<m)
        b=M[i][j]+help(M,n,m,i+1,j+1,memo);
        
        if(j+1<m)
        c=M[i][j]+help(M,n,m,i,j+1,memo);
        
        return memo[i][j]=max({a,b,c});
    }
    
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>> memo(n+1,vector<int>(m+1,-1));
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int a=help(M,n,m,i,0,memo);
            ans=max(a,ans);
        }
        
        return ans;
    }
};
 

/*-------------------TABULATION---------------*/
class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<vector<int>> dp(n,vector<int>(m,0));
        for(int j=m-1;j>=0;j--)
        {
            for(int i=0;i<n;i++)
            {
                int a,b,c;
                a=b=c=M[i][j];
                
                if(i-1>=0 and j+1<m)
                a+=dp[i-1][j+1];
                
                if(i+1<n and j+1<m)
                b+=dp[i+1][j+1];
                
                if(j+1<m)
                c+=dp[i][j+1];
                
                dp[i][j]=max({a,b,c});
            }
        }
        
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(dp[i][0],maxi);
        }
        
        return maxi;
    }
};
 

/*----------------------SPACE OPTIMIZED--------------*/
class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<int> pre(n,0);
        for(int j=m-1;j>=0;j--)
        {
            vector<int> curr(n,0);
            for(int i=0;i<n;i++)
            {
                int a,b,c;
                a=b=c=M[i][j];
                
                if(i-1>=0 and j+1<m)
                a+=pre[i-1];
                
                if(i+1<n and j+1<m)
                b+=pre[i+1];
                
                if(j+1<m)
                c+=pre[i];
                
                curr[i]=max({a,b,c});
            }
            pre=curr;
        }
        
        int maxi=0;
        for(int i=0;i<n;i++)
        {
            maxi=max(pre[i],maxi);
        }
        
        return maxi;
    }
};