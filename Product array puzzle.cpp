#define ll long long
class Solution {
    public:
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n=nums.size();
        int zeroCnt=0;
        
        ll pro=1;
        for(auto& it:nums)
        {
            if(it==0)
            zeroCnt++;
            
            if(it!=0)
            pro*=it;
        }
        
        // if there are two zeroes
        // every index will be zero
        if(zeroCnt>=2)
        {
            vector<ll> arr(n,0);
            return arr;
        }
        
        for(auto& it:nums)
        {
            if(zeroCnt>=1)
            {
                if(it==0)
                it=pro;
                else
                it=0;
                
                continue;
            }
            
            it=pro/it;
        }
        
        return nums;
    }
};
