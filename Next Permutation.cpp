class Solution {
    public:
    void nextPermutation(vector<int>& arr) {
        //check the break point 
        
        //     5
        //   2   4
        // 1       3
        //swap 2 to the number who is greater then 2 from back
        int n=arr.size();
        int ind=-1;
        for(int i=n-2;i>=0;i--)
        {
            if(arr[i]<arr[i+1])
            {
                ind=i;
                break;
            }
        }
        
        //if ind is still -1 that's mean array is in decreasing order
        //reverse the array
        if(ind==-1)
        {
            reverse(arr.begin(),arr.end());
            return ;
        }
        
        //swap the a[ind] to the greater value then a[ind] from back
        for(int i=n-1;i>=0;i--)
        {
            if(arr[i]>arr[ind])
            {
                swap(arr[i],arr[ind]);
                break;
            }
        }
        
        
        reverse(arr.begin()+ind+1,arr.end());
        //return arr;
    }
};
