#define ll long long
class Solution{
	public:
	
	int mod=1e9+7;
	ll inv(ll r)
	{
	    //base case
	    if(r==1)
	    return 1;
	    
	    //recursive calls
	    return (mod-((mod/r)*inv(mod%r))%mod+mod)%mod;
	}
	int compute_value(int n)
	{
	    ll ans=1;
	    ll ncr=1;
	    for(int i=1;i<=n;i++)
	    {
	        ncr=(((ncr*(n+1-i))%mod)*inv(i))%mod;
	        ans=(ans+(ncr*ncr)%mod)%mod;
	    }
	    
	    return ans%mod;
	}
};