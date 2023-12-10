// Time complexity - O(N)
// Space complexity- O(N)
class Solution{
    public:
    bool subArrayExists(int arr[], int n)
    {
        unordered_map<int,int> mp;
        mp[0]=-1;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
            if(sum==0)
            return 1;
            
            if(mp.count(sum))
            return 1;
            
            mp[sum]=i;
        }
        return 0;
    }
};
