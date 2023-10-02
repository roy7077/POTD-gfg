// Time Complexity: O(|str|)
// Auxiliary Space: O(|str|)
#define ll long long
class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    int mod=1e9+7;
	    int n=s.length();
	    vector<ll> dp(n+1,0);
	    unordered_map<ll,ll> mp;
	    
	    dp[0]=1;
	    for(int i=1;i<=s.length();i++)
	    {
	        char ch=s[i-1];
	        dp[i]=(2*dp[i-1])%mod;
	        if(mp.count(ch))
	        {
	            int ind=mp[ch];
	            dp[i]=((dp[i]-dp[ind-1]-1)+mod)%mod;
	        }
	        mp[ch]=i;
	    }
	    
	    return dp[n];
	}
};