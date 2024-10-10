// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int,int> mp;
        int maxDis=-1e9;
        
        for(int i=0;i<arr.size();i++)
        {
            if(mp.count(arr[i])==0)
            mp[arr[i]]=i;
            else
            maxDis=max(maxDis,i-mp[arr[i]]);
        }
        return maxDis;
    }
};
