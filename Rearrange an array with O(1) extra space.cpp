class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to rearrange an array so that arr[i] becomes arr[arr[i]]
    //with O(1) extra space.
    void arrange(long long arr[], int n) {
       
        long long max=1e9;
        for(int i=0;i<n;i++)
        {
            arr[i]=(arr[i]%max)+(arr[arr[i]]%max)*max;
        }
        
        for(int i=0;i<n;i++)
        arr[i]/=max;
        
    }
};
// time cm- O(N);
/// space com - O(1);