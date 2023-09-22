class Solution
{
    public:
    void lowerBound(int* arr,int s,int e,int x,int& ans)
    {
        //base case
        if(s>e)
        return ;
        
        //recursive calls
        int mid=(s+e)/2;
        if(arr[mid]==x)
        {
            ans=mid;
            return lowerBound(arr,s,mid-1,x,ans);
        }
        else if(arr[mid]>x)
        return lowerBound(arr,s,mid-1,x,ans);
        else
        return lowerBound(arr,mid+1,e,x,ans);
    }
    
    void UpperBound(int* arr,int s,int e,int x,int& ans)
    {
        //base case
        if(s>e)
        return ;
        
        //recursive calls
        int mid=(s+e)/2;
        if(arr[mid]==x)
        {
            ans=mid;
            return UpperBound(arr,mid+1,e,x,ans);
        }
        else if(arr[mid]>x)
        return UpperBound(arr,s,mid-1,x,ans);
        else
        return UpperBound(arr,mid+1,e,x,ans);
    }
    vector<int> find(int arr[], int n , int x )
    {
        int left=-1;
        int right=-1;
        
        lowerBound(arr,0,n-1,x,left);
        UpperBound(arr,0,n-1,x,right);
        
        if(right==-1)
        return {-1,-1};
        
        return {left,right};
    }
};
