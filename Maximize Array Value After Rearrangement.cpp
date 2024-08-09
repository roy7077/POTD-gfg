// Time complexity - O(NlogN)
// Space complexity- O(1)
int mod=1e9+7;
class Solution {
    public:
    int Maximize(vector<int> arr) {
        sort(arr.begin(),arr.end());
        long long sum=0;
        
        int n=arr.size();
        for(int i=0;i<n;i++)
        sum=(sum%mod+(((long long)arr[i])*i)%mod)%mod;
        
        return sum%mod;
    }
};
