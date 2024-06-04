// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    string binaryNextNumber(string s) {
        for(int i=s.length();i>=0;i--)
        {
            if(s[i]=='0')
            {
                s[i]='1';
                for(int j=0;j<s.length();j++)
                {
                    if(s[j]=='1')
                    return s.substr(j);
                }
            }
            s[i]='0';
        }
        return ('1'+s);
    }
};
