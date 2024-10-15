// Time complexity - O(N)
// Space complexity- O(N)
class Solution {
    public:
    int subArraySum(vector<int>& arr, int tar) {
        unordered_map<int,int> mp;
        int sum=0;
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum==tar)
            cnt++;
            
            cnt+=mp[sum-tar];
            mp[sum]++;
        }
        return cnt;
    }
};
