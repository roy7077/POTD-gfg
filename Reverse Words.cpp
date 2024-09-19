class Solution {
    public:
    string reverseWords(string s) {
        string ans="";
        string str="";
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='.')
            {
                if(ans.length())
                {
                    ans+=".";
                    ans+=str;
                }
                else
                ans+=str;
                
                str="";
            }
            else
            str=s[i]+str;
        }
        
        if(ans.length())
        {
            ans+=".";
            ans+=str;
        }
        else
        ans+=str;
        
        return ans;
    }
};
