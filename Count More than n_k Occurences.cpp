
/*----------------UNORDERED  MAP------------*/
// Time complexity - O(N)
// Space complexity- O(N)
class Solution
{
    public:
    int countOccurence(int arr[], int n, int k) {
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        mp[arr[i]]++;
        
        int cnt=0;
        for(auto it:mp)
        {
            if(it.second>(n/k))
            cnt++;
        }
        return cnt;
    }
};

/*-----------------SORTING----------------*/
// Time complexity - O(NlogN)
// Space complexity- O(1)
class Solution
{
    public:
    int countOccurence(int arr[], int n, int k) {
        sort(arr,arr+n);
        int ans=0;
        int cnt=1;
        for(int i=1;i<n;i++)
        {
            if(arr[i]==arr[i-1])
            cnt++;
            else
            {
                if(cnt>(n/k))
                ans++;
                
                cnt=1;
            }
        }
        
        if(cnt>(n/k))
        ans++;
        
        return ans;
    }
};