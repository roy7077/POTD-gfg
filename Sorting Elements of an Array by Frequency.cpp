class Solution {
    public:
    static bool cmp(pair<int,int>& a,pair<int,int>& b)
    {
        if(a.first!=b.first)
        return a.first>b.first;
        
        return a.second<b.second;
    }
    vector<int> sortByFreq(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(auto& it:arr)
        mp[it]++;
        
        vector<pair<int,int>> v;
        for(auto& it:mp)
        v.push_back({it.second,it.first});
        
        sort(v.begin(),v.end(),cmp);
        
        vector<int> ans;
        for(auto& it:v)
        {
            int size=it.first;
            while(size--)
            ans.push_back(it.second);
        }
        return ans;
    }
};
