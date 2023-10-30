/*------------BRUTE FORCE  ---->  OPTIMIZED APPROACH ----------------*/


/*------------BRUTE FORCE -> (TLE) ---------------*/
// Time complexity - O(N^2)
// Space complexity- O(1)
#define ll long long
class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	ll sum=0;
    	for(int i=0;i<n;i++)
    	{
    	    for(int j=i+1;j<n;j++)
    	    sum+=(arr[i]^arr[j]);
    	}
    	return sum;
    }
};


/*-----------OPTIMIZED APPROACH (Accepted)------------*/
// Time complexity - O(32*n)
// Space complexity- O(1)
#define ll long long
class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	ll sum=0;
    	for(int i=0;i<31;i++)
    	{
    	    ll one=0;
    	    ll zero=0;
    	
    	    for(int j=0;j<n;j++)
    	    {
    	        if(arr[j]&(1<<i))
    	        one++;
    	        else
    	        zero++;
    	    }
    	    
    	    ll p=one*zero;
    	    sum+=p*(1<<i);
    	}
    	return sum;
    }
};