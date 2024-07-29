// Time complexity - O(N)
// Space complexity- O(26)
class Solution {
    public:
    string removeDups(string str) {
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        while(j<str.length())
        {
            if(mp.count(str[j]))
            j++;
            else
            {
                mp[str[j]]=1;
                str[i]=str[j];
                i++;
                j++;
            }
        }
        return str.substr(0,i);
    }
};
