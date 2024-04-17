// Inversion count
// Time complexity - O(NlogN)
// Space complexity- O(NlogN)
class Solution{
    public:
    int cnt=0;
    void merge(int* arr,int s,int e)
    {
        int mid=(s+e)/2;
        int i=s;
        int j=mid+1;
        
        vector<int> temp;
        
        while(i<=mid and j<=e)
        {
            if(arr[i]>arr[j])
            {
                temp.push_back(arr[i]);
                cnt=cnt+(e-j+1);
                i++;
            }
            else
            {
                temp.push_back(arr[j]);
                j++;
            }
        }
        
        //copy elements left in left array
        while(i<=mid)
        {
            temp.push_back(arr[i]);
            i++;
        }
        
        //copy elements left in right array
        while(j<=e)
        {
            temp.push_back(arr[j]);
            j++;
        }
        
        
        //copy back to original array
        i=s;
        for(auto it:temp)
        {
            arr[i]=it;
            i++;
        }
    }
    void mergeSort(int* arr,int s,int e)
    {
        //base case
        if(s>=e)
        return ;
        
        //recursive calls
        //and small calculation
        int mid=(s+e)/2;
        mergeSort(arr,s,mid);
        mergeSort(arr,mid+1,e);
        merge(arr,s,e);
    }
    int countPairs(int arr[] , int n ) 
    {
        for(int i=0;i<n;i++)
        arr[i]=i*arr[i];
      
        mergeSort(arr,0,n-1);
        return cnt;
    }
};