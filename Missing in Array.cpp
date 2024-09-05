// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int missingNumber(int n, vector<int>& arr) {
        int totalSum=(n*(n+1))/2;
        int sum=0;
        for(auto& it:arr)
        sum+=it;
        
        return (totalSum-sum);
    }
};
