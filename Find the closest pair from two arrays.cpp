// Time complexity - O(N+M)
// Space complexity- O(1)
class Solution{
    public:
    vector<int> printClosest(int arr[], int brr[], int n, int m, int X) {
        
        int i=0;
        int j=m-1;
        pair<int,int> ans;
        int diff=1e9;
        while(i<n and j>=0)
        {
            int sum=arr[i]+brr[j];
            int d=abs(sum-X);
            
            if(d<diff)
            {
                diff=d;
                ans.first=arr[i];
                ans.second=brr[j];
            }
            
            if(sum==X)
            break;
            
            if(sum<X)
            i++;
            else
            j--;
        }
        
        return {ans.first,ans.second};
    }
};