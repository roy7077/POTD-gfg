// Time complexity - O(N)
// Space complexity- O(1)
class Solution{
    public:
    bool isMaxHeap(int arr[], int n)
    {
        int i=0;
        while(i<n)
        {
            int child1=(2*i)+1;
            int child2=(2*i)+2;
            
            if(child1<n and arr[child1]>arr[i])
            return 0;
            
            if(child2<n and arr[child2]>arr[i])
            return 0;
        
            i++;
        }
        return 1;
    }
};