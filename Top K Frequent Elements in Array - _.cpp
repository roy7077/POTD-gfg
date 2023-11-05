class Solution {
    public:
    static bool cmp(pair<int,int> a,pair<int,int> b)
    {
        if(a.first>b.first)
        return 1;
        else if(a.first==b.first)
        return a.second>b.second;
        else
        return 0;
    }
    vector<int> topK(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        vector<pair<int,int>> pv;
        int cnt=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            cnt++;
            else
            {
                pv.push_back({cnt,nums[i-1]});
                cnt=1;
            }
        }
        pv.push_back({cnt,nums[nums.size()-1]});
        sort(pv.begin(),pv.end(),cmp);
        
        vector<int> ans;
        for(auto it:pv)
        {
            ans.push_back(it.second);
            if(ans.size()==k)
            break;
        }
        return ans;
    }
};
