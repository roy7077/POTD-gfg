// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int getSingle(vector<int>& arr) {
        int xorr=0;
        for(auto& it:arr)
        xorr^=it;
        
        return xorr;
    }
};
