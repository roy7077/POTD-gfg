class Solution {
    public:
    bool KMP(string& text,string& pat){
        int n=text.length();
        int m=pat.length();
        
        string matchingString=text+'$'+pat;
        vector<int> lps(matchingString.length(),0);
        int j=1;
        int len=0;
        while(j<matchingString.length())
        {
            if(matchingString[j]==matchingString[len]){
                lps[j]=len+1;
                j++;
                len++;
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
        
        int maxi=0;
        for(int i=lps.size()-1;i>=0;i--)
        maxi=max(maxi,lps[i]);
        
        string temp=text.substr(maxi)+text.substr(0,maxi);
        if(temp==pat)
        return 1;
        return 0;
    }
    bool areRotations(string &s1, string &s2) {
        return KMP(s1,s2);
    }
};


// abcd
// acbd

// str1=a
// cbda

// str=ac
// bdac

// str=acb
// dacb
