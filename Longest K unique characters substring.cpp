class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        unordered_map<char,int> mp;
        int maxi=0;
        int n=s.length();
        int i=0;
        for(int j=0;j<n;j++)
        {
            mp[s[j]]++;
            while(mp.size()>k and i<n)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0)
                mp.erase(s[i]);
                
                i++;
            }
            
            if(mp.size()==k)
            maxi=max(j-i+1,maxi);
        }
        
        return maxi==0 ? -1 : maxi;
    }
};