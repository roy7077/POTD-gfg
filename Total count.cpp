class Solution {
    public:
    int totalCount(int k, vector<int>& arr) {
        int cnt=0;
        for(auto& it: arr)
        {
            cnt+=(it/k);
            
            if(it%k)
            cnt++;
        }
        return cnt;
    }
};
