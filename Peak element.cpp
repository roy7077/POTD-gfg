

/* Method -1
   Time complexity - O(N)
   Space complexity- O(1)
*/
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       int index=-1;
       for(int i=0;i<n;i++)
       {
           if(i-1>=0 and i+1<n)
           {
               if(arr[i]>=arr[i-1] and arr[i]>=arr[i+1])
               index=i;
           }
           else if(i-1>=0)
           {
               if(arr[i]>=arr[i-1])
               index=i;
           }
           else if(i+1<n)
           {
               if(arr[i]>=arr[i+1])
               index=i;
           }
           else
           index=i;
       }
       return index;
    }
};

/* Method -2
   Time complexity - O(LogN)
   Space complexity- O(1)
*/
class Solution
{
    public:
    int peakElement(int arr[], int n)
    {
       int l=0;
       int r=n-1;
       while(l<r)
       {
           int mid=(l+r)/2;
           if(arr[mid]<arr[mid+1])
           l=mid+1;
           else
           r=mid;
       }
       return l;
    }
};