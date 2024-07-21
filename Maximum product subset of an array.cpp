// User function Template for C++

// Time complexity - O(N)
// Space complexity- O(1)
int mod=1e9+7;
#define ll long long
class Solution {
    public:
    long long int findMaxProduct(vector<int>& arr) {
        ll ans=1;
        int mini=1e9;
        
        for(auto& it:arr)
        {
            if(it==0)
            continue;
            
            ans=(ans*it)%mod;
            
            if(it<0)
            mini=min(mini,abs(it));
        }
        
        if(ans>0 or arr.size()==1)
        return ans;
        
        ans=abs(ans)/mini;
        return ans;
    }
};
