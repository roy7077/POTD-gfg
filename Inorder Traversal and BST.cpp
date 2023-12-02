// ALL  POSSIBLE  APPROACHES

/*-------------- RECURSION || T - O(N) || S - O(N) ----------*/
// Time complexity - O(N)
// Space complexity- o(N)
class Solution{
    public:
    
    bool help(int* arr,int parent,int s,int e,bool flag)
    {
        //base case
        if(s>e)
        return 1;
        
        int mid=(s+e)/2;
        int node=arr[mid];
        
        if(flag)
        {
            if(node>=parent)
            return 0;
        }
        else
        {
            if(node<parent)
            return 0;
        }
        
        bool left=help(arr,node,s,mid-1,1);
        if(!left)
        return 0;
        
        bool right=help(arr,node,mid+1,e,0);
        
        return right;
    }
    
    int isRepresentingBST(int arr[], int N)
    {
        int mid=(0+(N-1))/2;
        int node=arr[mid];
        bool a=help(arr,node,0,mid-1,1);
        if(!a)
        return 0;
        
        bool b=help(arr,node,mid+1,N-1,0);
        return b;
    }
};

/*----------Check ISsorted || T - O(N) || S - O(N)------------*/
// Time complexity - O(N)
// Space complexity- o(1)
class Solution{
    public:
    int isRepresentingBST(int arr[], int N)
    {
        for(int i=0;i<(N-1);i++)
        {
            if(arr[i+1]<arr[i])
            return 0;
        }
        
        return 1;
    }
};
/*-----------INBUILT FUNCTION || T - O(N) || S - O(1)------------*/
// Time complexity - O(N)
// Space complexity- o(1)
class Solution{
    public:
    int isRepresentingBST(int arr[], int N)
    {
        return is_sorted(arr,arr+N);
    }
};