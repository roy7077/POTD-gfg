
// Time complexity - O(logn + logm)
// Space complexity- O(logn)
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        int low=min(arr1[0],arr2[0]);
        int high=max(arr1[n-1],arr2[m-1]);
        
        while(low<high)
        {
            int mid=(low+high)/2;
            
            int x=upper_bound(arr1,arr1+n,mid)-arr1;
            int y=upper_bound(arr2,arr2+m,mid)-arr2;
            
            if((x+y)<k)
            low=mid+1;
            else
            high=mid;
        }
        
        return low;
    }
};
