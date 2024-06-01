class Solution {
    public:
    string oddEven(string s) {
        unordered_map<char,int> mp;
        for(auto& ch:s)
        mp[ch]++;
        
        int odd=0;
        int even=0;
        
        for(auto& it:mp)
        {
            if((it.first-'a'+1)&1 and it.second&1)
            odd++;
            else if((it.first-'a'+1)%2==0 and it.second%2==0)
            even++;
        }
        
        if((odd+even)&1)
        return "ODD";
        else
        return "EVEN";
    }
};