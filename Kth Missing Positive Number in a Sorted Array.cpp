
class Solution {
    public:
    int kthMissing(vector<int> &arr, int k) {
        unordered_map<int,int> mp;
        for(auto& it:arr)
        mp[it]++;
        
        for(int i=1;i<=1000000;i++)
        {
            if(!mp.count(i))
            {
                k--;
                if(k==0)
                return i;
            }
        }
        return -1;
    }
};
