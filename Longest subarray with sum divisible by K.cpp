//UNORDERED MAP || T - O(N) || S - O(N)
// Time complexity - O(N)
// Space complexity- O(N)
#define ll long long
class Solution{
    public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int,int> mp;
	    mp[0]=-1;
	    
	    int ind=0;
	    int sum=0;
	    for(int i=0;i<n;i++)
	    {
	        sum+=arr[i];
	        int rem=sum%k;
	        
	        if(rem<0)
	        rem+=k;
	        
            if(mp.count(rem))
            ind=max(ind,i-mp[rem]);
            else
            mp[rem]=i;
	     }
	     return ind;
	}
};