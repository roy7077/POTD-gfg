// Time complexity - O(LogN)
// Space complexity- O(1)
class Solution{
    public:
    int binarySearch(int* arr,int& n,int& k)
    {
        int s=0;
        int e=n-1;
        int ans=-1;
        int minDif=1e9;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(arr[mid]==k)
            return k;
            else if(arr[mid]>k)
            {
                if((arr[mid]-k)<minDif)
                {
                    minDif=arr[mid]-k;
                    ans=arr[mid];
                }
                else if((arr[mid]-k)==minDif)
                ans=max(ans,arr[mid]);
                
                e=mid-1;
            }
            else
            {
                if((k-arr[mid])<minDif)
                {
                    minDif=k-arr[mid];
                    ans=arr[mid];
                }
                else if((k-arr[mid])==minDif)
                ans=max(ans,arr[mid]);
                
                s=mid+1;
            }
        }
        return ans;
    }
    int findClosest( int n, int k,int arr[]) 
    { 
        return binarySearch(arr,n,k);
    } 
};
