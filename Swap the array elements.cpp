// Time complexity - O(N)
// Space complexity- O(1)
class Solution{
    public:
    void swapElements(int arr[], int n){
       int i=0;
       while(i+2<n)
       {
           swap(arr[i],arr[i+2]);
           i++;
       }
    }
};
