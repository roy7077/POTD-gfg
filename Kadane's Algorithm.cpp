
class Solution {
    public:
    long long maxSubarraySum(vector<int> &arr) {
        long long sum=0;
        long long maxi=-1e9;
        for(auto& it:arr)
        {
            sum+=it;
            maxi=max(maxi,sum);
            
            if(sum<0)
            sum=0;
        }
        return maxi;
    }
};
