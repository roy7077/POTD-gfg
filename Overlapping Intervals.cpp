// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
    
        sort(arr.begin(),arr.end(),[&](vector<int>& a,vector<int>& b){
            if(a[0]!=b[0])
            return a[0]<b[0];
            
            return a[1]<b[1];
        });
        
        vector<vector<int>> ans;
        int start=arr[0][0];
        int end=arr[0][1];
        
        for(int i=1;i<arr.size();i++)
        {
            if(end>=arr[i][0])
            end=max(end,arr[i][1]);
            else
            {
                ans.push_back({start,end});
                start=arr[i][0];
                end=arr[i][1];
            }
        }
        
        ans.push_back({start,end});
        return ans;
    }
};
