// Time complexity - O(N)
// Space complexity- O(1)
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to sort the array into a wave-like array.
    void convertToWave(int n, vector<int>& arr){
        
        int i=0;
        while(i<arr.size()-1)
        {
            int temp=arr[i+1];
            arr[i+1]=arr[i];
            arr[i]=temp;
            i+=2;
        }
    }
};