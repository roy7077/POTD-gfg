class Solution {
    public:
    long long findSmallest(vector<int> &arr) {
        int res=1;
        for (int i=0;i<arr.size();i++){
            if(arr[i]<=res){
                res+=arr[i];
            }
        }
        return res;
    }
};
