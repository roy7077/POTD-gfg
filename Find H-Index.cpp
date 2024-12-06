// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution {
    public:
    int hIndex(vector<int>& citations) {
        int s=0;
        int e=1e9;
        int ans=0;
        while(s<=e)
        {
            int mid=(s+e)/2;
            int cnt=0;
            for(auto& it:citations)
            {
                if(it>=mid)
                cnt++;
            }
            
            if(cnt>=mid)
            {
                ans=mid;
                s=mid+1;
            }
            else
            e=mid-1;
        }
        return ans;
    }
};
