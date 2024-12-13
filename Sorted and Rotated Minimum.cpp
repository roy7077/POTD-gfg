class Solution {
    public:
    int findMin(vector<int>& arr) {
        int s=0;
        int e=arr.size()-1;
        int ans=1e9;
        
        while(s<=e)
        {
            int mid=(s+e)/2;
            
            // if you are in same line
            if(arr[s]<=arr[mid] and arr[mid]<=arr[e])
            {
                ans=min(ans,arr[mid]);
                e=mid-1;
            }
            else if(arr[mid]>=arr[s] and arr[mid]>=arr[e])
            {
                ans=min(ans,arr[mid]);
                s=mid+1;
            }
            else
            {
                ans=min(ans,arr[mid]);
                e=mid-1;
            }
        }
        return ans;
    }
};
