// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            if(mp.count(arr[i]))
            {
                if((i-mp[arr[i]])<=k)
                return 1;
            }
            
            mp[arr[i]]=i;
        }
        return 0;
    }
};
