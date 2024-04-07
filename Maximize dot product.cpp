
// Recursion - TLE for sure
class Solution{
	public:
	int help(int* a,int* b,int i,int j)
	{
	    //base case
	    if(j<0)
	    return 0;
	    
	    if(i<0)
	    return 0;
	    //recursive calls
	    //and small calculation
	    int maxi=0;
	    for(int k=i;k>=0;k--)
	    {
	        int temp=a[k]*b[j]+help(a,b,k-1,j-1);
	        if(temp>maxi)
	        maxi=temp;
	    }
	    return maxi;
	}
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
		int ans=help(a,b,n-1,m-1);
		return ans;
	} 
};


// Memoization
class Solution{
	public:
	int help(int* a,int* b,int i,int j,vector<vector<int>>& memo)
	{
	    //base case
	    if(j<0)
	    return 0;
	    
	    if(i<0)
	    return -1e9;
	    
	    //memo check
	    if(memo[i][j]!=-1)
	    return memo[i][j];
	    
	    //recursive calls
	    //and small calculation
	    
	    int nottake=0+help(a,b,i-1,j,memo);
	    int take=a[i]*b[j]+help(a,b,i-1,j-1,memo);
	    
	    return memo[i][j]=max(take,nottake);
	}
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
	    vector<vector<int>> memo(n,vector<int>(m,-1));
		int ans=help(a,b,n-1,m-1,memo);
		return ans;
	} 
};


// Tabulation
class Solution{
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
	    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
		for(int i=1;i<(n+1);i++)
		{
		    for(int j=1;j<(m+1);j++)
		    {
		        if(i==0 or j==0)
		        continue;
		        
	             else if(i==j){
	                 dp[i][j]=a[i-1]*b[j-1]+dp[i-1][j-1];
	             }
	             else if(i>j){
	                 dp[i][j]=max(a[i-1]*b[j-1]+dp[i-1][j-1],dp[i-1][j]);
	             }
		    }
		}
		
		return dp[n][m];
	} 
};


// Space optimized
class Solution{
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) 
	{ 
	    vector<int> pre(m+1,0);
		for(int i=1;i<(n+1);i++)
		{
		    vector<int> curr(m+1,0);
		    for(int j=1;j<(m+1);j++)
		    {
		        if(i==0 or j==0)
		        continue;
		        
	             else if(i==j)
	             curr[j]=a[i-1]*b[j-1]+pre[j-1];
	             else if(i>j)
	             curr[j]=max(a[i-1]*b[j-1]+pre[j-1],pre[j]);
		    }
		    pre=curr;
		}
		
		return pre[m];
	} 
};
