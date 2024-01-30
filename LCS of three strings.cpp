/*---------3D - Dynammic Programming--------------*/

// THREE  APPROACHES || MEMOIZATION || TABULATION || SPACE OPTIMIZED 

// MEMOIZATION
class Solution
{
        public:
        int help(string& s1,string& s2,string& s3,int i,int j,int k,vector<vector<vector<int>>>& memo)
        {
            //base case
            if(i<0 or j<0 or k<0)
            return 0;
            
            //memo check
            if(memo[i][j][k]!=-1)
            return memo[i][j][k];
            
            //recursive calls
            //ans small calculation
            if(s1[i]==s2[j] and s1[i]==s3[k])
            return 1+help(s1,s2,s3,i-1,j-1,k-1,memo);
            
            int a=help(s1,s2,s3,i-1,j,k,memo);
            int b=help(s1,s2,s3,i,j-1,k,memo);
            int c=help(s1,s2,s3,i,j,k-1,memo);
            
            return memo[i][j][k]=max({a,b,c});
            
        }
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            vector<vector<vector<int>>> memo(n1,vector<vector<int>>(n2,vector<int>(n3,-1)));
            return help(A,B,C,n1-1,n2-1,n3-1,memo);
        }
};

// TABULATION
class Solution
{
        public:
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            vector<vector<vector<int>>> dp(n1+1,vector<vector<int>>(n2+1,vector<int>(n3+1,0)));
            for(int i=1;i<=n1;i++)
            {
                for(int j=1;j<=n2;j++)
                {
                    for(int k=1;k<=n3;k++)
                    {
                        if(A[i-1]==B[j-1] and A[i-1]==C[k-1])
                        {
                            dp[i][j][k]=1+dp[i-1][j-1][k-1];
                            continue;
                        }
                        
                        int a=dp[i-1][j][k];
                        int b=dp[i][j-1][k];
                        int c=dp[i][j][k-1];
                        
                        dp[i][j][k]=max({a,b,c});
                    }
                }
            }
            return dp[n1][n2][n3];
        }
};

// SPACE OPTIMIZED
class Solution
{
        public:
        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            vector<vector<int>> pre(n2+1,vector<int>(n3+1,0));
            for(int i=1;i<=n1;i++)
            {
                vector<vector<int>> curr(n2+1,vector<int>(n3+1,0));
                for(int j=1;j<=n2;j++)
                {
                    for(int k=1;k<=n3;k++)
                    {
                        if(A[i-1]==B[j-1] and A[i-1]==C[k-1])
                        {
                            curr[j][k]=1+pre[j-1][k-1];
                            continue;
                        }
                        
                        int a=pre[j][k];
                        int b=curr[j-1][k];
                        int c=curr[j][k-1];
                        
                        curr[j][k]=max({a,b,c});
                    }
                }
                pre=curr;
            }
            return pre[n2][n3];
        }
};