/*------using unordered map--------*/
//Time complexity - O(N)
//Space complexity- O(N)
class Solution {
    public:
    bool canPair(vector<int> nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums)
        mp[it%k]++;
        
        if(mp[0]%2)
        return 0;
        
        for(int i=1;i<k;i++)
        {
            if(mp[i]!=mp[k-i])
            return 0;
        }
        
        return 1;
    }
};

/*------using sorting--------*/
//Time complexity - O(NlogN)
//Space complexity- O(1)
class Solution {
    public:
    bool canPair(vector<int> nums, int k) {
        int cnt=0;
        for(auto& it:nums)
        {
            if(it%k==0)
            {
                cnt++;
                it=0;
            }
            else
            it=it%k;
        }
        
        if(cnt%2)
        return 0;
        
        sort(nums.begin(),nums.end());
        int s=cnt;
        int e=nums.size()-1;
        
        while(s<e)
        {
            if((nums[s]+nums[e])%k)
            return 0;
            else
            s++,e--;
        }
        
        return 1;
    }
};
