class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        
        int cnt=0;
        sort(arr.begin(),arr.end());
        set<vector<int>> st;
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                int l=j+1;
                int r=arr.size()-1;
                
                while(l<r)
                {
                    if((arr[i]+arr[j]+arr[l]+arr[r])==k)
                    {
                        st.insert({arr[i],arr[j],arr[l],arr[r]});
                        l++;
                        r--;
                    }
                    else if((arr[i]+arr[j]+arr[l]+arr[r])<k)
                    l++;
                    else
                    r--;
                }
            }
        }
        
        vector<vector<int>> ans;
        for(auto it:st)
        ans.push_back(it);
        
        return ans;
    }
};