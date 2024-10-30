// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int countPairsWithDiffK(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(auto& it:arr)
        mp[it]++;
        
        int cnt=0;
        for(auto& it:arr)
        {
            if(mp.count(k+it))
            cnt+=mp[k+it];
        }
        return cnt;
    }
};
