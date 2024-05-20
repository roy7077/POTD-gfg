// Time complexity - O(LogN)
// Space complexity- O(1)
#define ll long long
class Solution
{
	public:
	ll power(ll base,ll n,ll mod)
	{
	    ll ans=1;
	    while(n)
	    {
	        if(n&1)
	        {
	            ans=(ans*base)%mod;
	            n--;
	        }
	        else
	        {
	            base=(base*base)%mod;
	            n/=2;
	        }
	    }
	    return ans;
	}
	long long int PowMod(long long int x,long long int n,long long int M)
	{
	    return power(x,n,M);
	}
};