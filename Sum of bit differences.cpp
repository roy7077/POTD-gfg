/*-----Method - 2 ------*/
// Time complexity - O(32*N)
// Space complexity- O(1)
#define ll long long
class Solution{
    public:
	long long sumBitDifferences(int arr[], int n) {
	    ll ans=0;
	    for(int i=0;i<=31;i++)
	    {
	        ll zeros=0;
	        ll ones=0;
	        for(int j=0;j<n;j++)
	        {
	            if(arr[j]&(1<<i))
	            ones++;
	            else
	            zeros++;
	        }
	        ans+=(zeros*ones);
	    }
	    return 2*ans;
	}
};