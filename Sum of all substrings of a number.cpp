// Proper mathematics
// Time complexity - O(N)
// Space complexity- O(1)
#define ll long long 
int mod=1e9+7;
class Solution
{
    public:
    long long sumSubstrings(string s){
        ll pre=s[0]-'0';
        ll ans=pre;
        for(int i=1;i<s.length();i++)
        {
            ll curr=(((i+1)*(s[i]-'0'))%mod+(pre*10))%mod;
            ans=(ans+curr)%mod;
            pre=curr;
        }
        return ans;
    }
};