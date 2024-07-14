// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    void segregate0and1(vector<int> &arr) {
        int i=0;
        int j=0;
        while(j<arr.size())
        {
            if(arr[j]==0)
            {
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
                i++;
            }
            j++;
        }
    }
};
