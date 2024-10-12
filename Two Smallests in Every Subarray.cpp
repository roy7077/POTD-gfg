class Solution {
    public:
    int pairWithMaxSum(vector<int>& arr) {
        
        if(arr.size()==1 or arr.size()==0)
        return -1;
        
        int maxSum=0;
        for(int i=0;i<arr.size()-1;i++)
        {
            if((arr[i]+arr[i+1])>maxSum)
            maxSum=arr[i]+arr[i+1];
        }
        
        return maxSum;
    }
};
