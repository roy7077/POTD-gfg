class Solution {
    public:
    char nonRepeatingChar(string &s) {
        unordered_map<char,int> mp;
        for(auto& it:s)
        mp[it]++;
        
        if(mp.size()==1 and s.length()>1)
        return '$';
        
        for(auto& it:s)
        {
            if(mp[it]==1)
            return it;
        }
        
        return '$';
    }
};
