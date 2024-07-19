// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    string printString(string s, char ch, int count) {
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==ch)
            {
                count--;
                if(!count and (i+1)<s.length())
                return s.substr(i+1);
            }
        }
        return "";
    }
};
