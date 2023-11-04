/*-----------LINEAR SEARCH--------------*/
// Time complexity - O(N)
class Solution
{
    public:    
    int transitionPoint(int arr[], int n) {
        for(int i=0;i<n;i++)
        {
            if(arr[i])
            return i;
        }
        return -1;
    }
};

/*---------------BINARY SEARCH-------------*/
// Time complexity - O(LogN)
class Solution
{
    public:    
    void help(int* arr,int s,int e,int& ind)
    {
        //base case
        if(s>e)
        return ;
        
        int mid=(s+e)/2;
        if(arr[mid])
        {
            ind=mid;
            help(arr,s,mid-1,ind);
        }
        else if(!arr[mid])
        help(arr,mid+1,e,ind);
    }
    
    int transitionPoint(int arr[], int n) {
        int ind=-1;
        help(arr,0,n-1,ind);
        
        return ind==-1?-1:ind;
    }
};