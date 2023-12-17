//ALL  POSSIBLE  APPROACHES


/*-----------------RECURSION (TLE)------------*/
//User function template for C++
class Solution{
    public:	
	int help(int* arr,int i)
	{
	    //base case
	    if(i==0)
	    return arr[0];
	    
	    if(i<0)
	    return 0;
	    
	    //recursive calls
	    //small calculation
	    int a=help(arr,i-1);
	    int b=arr[i]+help(arr,i-2);
	    
	    return max(a,b);
	}
	int findMaxSum(int *arr, int n) {
	    return help(arr,n-1);
	}
};

/*---------------MEMOIZATION------------------*/
//User function template for C++
class Solution{
    public:	
	int help(int* arr,int i,vector<int>& memo)
	{
	    //base case
	    if(i==0)
	    return arr[0];
	    
	    if(i<0)
	    return 0;
	    
	    //memo check
	    if(memo[i]!=-1)
	    return memo[i];
	    
	    //recursive calls
	    //small calculation
	    int a=help(arr,i-1,memo);
	    int b=arr[i]+help(arr,i-2,memo);
	    
	    return memo[i]=max(a,b);
	}
	int findMaxSum(int *arr, int n) {
	    vector<int> memo(n,-1);
	    return help(arr,n-1,memo);
	}
};


/*----------------------TABULATION----------------*/
//User function template for C++
class Solution{
    public:	
	int findMaxSum(int *arr, int n) {
	    vector<int> dp(n,0);
	    dp[0]=arr[0];
	    dp[1]=max(arr[0],arr[1]);
	    for(int i=2;i<n;i++)
	    {
	        int a=dp[i-1];
	        int b=arr[i]+dp[i-2];
	        
	        dp[i]=max(a,b);
	    }
	    return dp[n-1];
	}
};


/*-----------------------SPACE OPTIMIZED--------------*/
//User function template for C++
class Solution{
    public:	
	int findMaxSum(int *arr, int n) {
	    if(n==1)
	    return arr[0];
	    
	    int a=arr[0];
	    int b=max(arr[0],arr[1]);
	    for(int i=2;i<n;i++)
	    {
	        int temp1=b;
	        int temp2=arr[i]+a;
	        int curr=max(temp1,temp2);
	        
	        a=b;
	        b=curr;
	    }
	    return b;
	}
};
