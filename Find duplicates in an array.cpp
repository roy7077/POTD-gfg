class Solution{
    public:
    vector<int> duplicates(int arr[], int n) {
        
        unordered_map<int,int> mp;
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            if(mp[arr[i]]==1)
            {
                ans.push_back(arr[i]);
                mp[arr[i]]++;
            }
            else if(mp[arr[i]]==0)
            mp[arr[i]]=1;
        }
        
        if(ans.size()==0)
        return {-1};
        else
        {
            sort(ans.begin(),ans.end());
            return ans;
        }
    }
};