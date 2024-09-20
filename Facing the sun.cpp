// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int countBuildings(vector<int> &height) {
        int maxi=0;
        int cnt=0;
        for(auto& it:height)
        {
            if(it>maxi)
            cnt++;
            
            maxi=max(maxi,it);
        }
        return cnt;
    }
};
