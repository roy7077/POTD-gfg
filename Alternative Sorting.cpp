class Solution {
    public:
    vector<int> alternateSort(vector<int>& arr) {
        sort(arr.begin(),arr.end(),greater<int>());
        vector<int> ans(arr.size());
        int i=0;
        int j=arr.size()-1;
        bool flag=1;
        
        for(auto& it:ans)
        {
            if(flag)
            it=arr[i++];
            else
            it=arr[j--];
            
            flag=(!flag);
        }
        
        return ans;
    }
};
