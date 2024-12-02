class Solution {
    public:
    vector<int> KMP(string& text,string& pat)
    {
        int n=text.length();
        int m=pat.length();
        
        pat=pat+'$'+text;
        vector<int> lps(pat.size(),0);
        
        int len=0;
        int j=1;
        
        while(j<lps.size())
        {
            if(pat[len]==pat[j])
            {
                lps[j]=len+1;
                len++;
                j++;
            }
            else
            {
                if(len)
                len=lps[len-1];
                else
                {
                    lps[j]=0;
                    j++;
                }
            }
        }
        
        //      5678
        // geek$geeksforgeeks
        vector<int> indexes;
        for(int i=0;i<lps.size();i++)
        {
            if(lps[i]==m)
            indexes.push_back(i-(m+1)-(m-1));
        }
        
        return indexes;
    }
    vector<int> search(string& pat, string& txt) {
        return KMP(txt,pat);
    }
};
