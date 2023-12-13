// Time complexity - O(N)
// Space complexity- O(1)
#define ll long long
int mod=1e9+7;
class Solution{
    public:
	ll countStrings(int n) {
	    ll a=2;
	    ll b=3;
	    
	    for(int i=2;i<=n;i++)
	    {
	        ll temp=(a+b)%mod;
	        a=b;
	        b=temp;
	    }
	    return a;
	}
};