class Solution {
  public:
    int leastInterval(int N, int K, vector<char> &tasks) {
        
        int max_count=0;
        int maxi=0;
        
        map<char,int> mp;
        for(auto it:tasks)
        {
            mp[it]++;
            maxi=max(mp[it],maxi);
        }
        
        for(auto it:mp)
        {
            if(it.second==maxi)
            max_count++;
        }
        
        int ans=max(N,max_count+((maxi-1)*(K+1)));
        return ans;
        return 0;
    }
};