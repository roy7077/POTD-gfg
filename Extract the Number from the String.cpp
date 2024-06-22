// User function Template for C++

// Time complexity - O(N)
// Space complexity- O(1)
#define ll long long
class Solution {
    public:
    string help(string s1,string s2)
    {
        for(auto& it:s2)
        {
            if(it=='9')
            return s1;
        }
        
        if(s1.length()>s2.length())
        return s1;
        else if(s2.length()>s1.length())
        return s2;
        
        for(int i=0;i<s1.length();i++)
        {
            if(s1[i]>s2[i])
            return s1;
            else if(s2[i]>s1[i])
            return s2;
        }
        
        return s2;
    }
    long long ExtractNumber(string sentence) {
        string ans="";
        string str="";
        bool isNine=0;
        for(auto& it:sentence)
        {
            if(it==' ')
            {
                ans=help(ans,str);
                str="";
                isNine=0;
            }
            else if(!isNine and it>='0' and it<='9')
            {
                if(it=='9')
                {
                    isNine=1;
                    continue;
                }
                str+=it;
            }
        }
      
        if(ans.length()==0)
        return -1;
        
        ll finalAns=0;
        for(auto& it:ans)
        {
            finalAns*=10;
            finalAns+=(it-'0');
        }
        return finalAns;
    }
};
