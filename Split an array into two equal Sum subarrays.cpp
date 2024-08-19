class Solution {
    public:
    bool canSplit(vector<int>& arr) {
        
        long long totalSum=0;
        for(auto& it:arr)
        totalSum+=it;
        
        long long sum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum==(totalSum-sum))
            return 1;
        }
        return 0;
    }
};
