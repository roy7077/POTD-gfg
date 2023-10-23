/*-----😎  All  POSSIBLE  APPROACHES 🔥----------*/


//RECURSION
class Solution{
	public:
	int help(int* arr,int i,int n,int last)
	{
	    //base case
	    if(i==n)
	    return 0;
	    
	    //recursive call
	    //small calculation
	    int a=help(arr,i+1,n,last);
	    int b=0;
	    if(arr[i]>last)
	    b=arr[i]+help(arr,i+1,n,arr[i]);
	    
	    return max(a,b);
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    int ans=help(arr,0,n,-1);
	    return ans;
	}  
};


//MEMOIZATION
class Solution{
	public:
	int help(int* arr,int i,int n,int last,vector<vector<int>>& memo)
	{
	    //base case
	    if(i==n)
	    return 0;
	    
	    //memo check
	    if(memo[i][last]!=-1)
	    return memo[i][last];
	    
	    //recursive call
	    //small calculation
	    int a=help(arr,i+1,n,last,memo);
	    int b=0;
	    if(arr[i]>last)
	    b=arr[i]+help(arr,i+1,n,arr[i],memo);
	    
	    return memo[i][last]=max(a,b);
	}
	
	int maxSumIS(int arr[], int n)  
	{  
	    int maxi=-1;
	    for(int i=0;i<n;i++)
	    maxi=max(maxi,arr[i]);
	    
	    vector<vector<int>> memo(n+1,vector<int>(maxi+1,-1));
	    int ans=help(arr,0,n,0,memo);
	    return ans;
	   
	}  
};


//TABULATION
class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{ 
	    vector<vector<int>> DP(n+1,vector<int>(n+1,0));
	    for(int i=n-1;i>=0;i--)
	    {
	        for(int j=-1;j<i;j++)
	        {
	            int a,b;
	            a=b=0;
	            
	            a=DP[i+1][j+1];
	            if(j==-1 or arr[i]>arr[j])
	            b=arr[i]+DP[i+1][i+1];
	            
	            DP[i][j+1]=max(a,b);
	        }
	    }
	    return DP[0][-1+1];
	}  
};


//SPACE OPTIMIZED
class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{ 
	    vector<int> next(n+1,0);
	    for(int i=n-1;i>=0;i--)
	    {
	        vector<int> curr(n,0);
	        for(int j=-1;j<i;j++)
	        {
	            int a,b;
	            a=b=0;
	            
	            a=next[j+1];
	            if(j==-1 or arr[i]>arr[j])
	            b=arr[i]+next[i+1];
	            
	            curr[j+1]=max(a,b);
	        }
	        next=curr;
	    }
	    return next[-1+1];
	}  
};