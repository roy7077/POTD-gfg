
// Method - 1
// Soring
// Time complexity - O(NlogN)
// Space complexity- O(1)
/*sort the array and then iterate over array and 
find the single one. if we came out of the loop 
and didn't get single one that's mean the element
at the last index in the array is single one
*/
class Solution{
    public:
    int findSingle(int n, int arr[]){
        sort(arr,arr+n);
        int i=0;
        while(i<n-1)
        {
            if(arr[i]==arr[i+1])
            i+=2;
            else
            return arr[i];
        }
        return arr[n-1];
    }
};


// Method - 2
// frequency array
// Time complexity - O(N)
// Space complexity- O(N)
/*store the frequency of each element in a frequency array . 
then iterate over frequency array and check for the odd 
element that will be our answer.

I am using a frequency array instead of an unordered map 
because I was getting TLE (Time Limit Exceeded) when I 
used an unordered map
*/
class Solution{
    public:
    int findSingle(int n, int arr[]){
        int freq[1000002]={0};
        for(int i=0;i<n;i++)
        freq[arr[i]]++;
            
        for(int i=0;i<1000002;i++)
        {
            if(freq[i]&1)
            return i;
        }
        return -1;
    }
};


// Method - 3
// XOR
// Time complexity - O(N)
// Space complexity- O(1)
/* We know that the XOR of the same element is 0. 
Iterate over the array and calculate the XOR of each 
element. The same elements will cancel each other out, 
and in the end, there will be only a single element left 
in the XOR, which will be our answer.
*/
class Solution{
    public:
    int findSingle(int n, int arr[]){
        int xorr=0;
        for(int i=0;i<n;i++)
        xorr^=arr[i];
        
        return xorr;
    }
};