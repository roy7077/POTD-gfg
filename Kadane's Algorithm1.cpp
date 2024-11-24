// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int maxSubarraySum(vector<int> &arr) {
        int maxSum=-1e9;
        int sum=0;
        for(auto& it:arr)
        {
            sum+=it;
            maxSum=max(maxSum,sum);
            
            if(sum<0)
            sum=0;
        }
        
        return maxSum;
    }
};
