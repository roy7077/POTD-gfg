/*----------TWO  APPROACHES-----------*/

//METHOD - 1
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int smallestSubstring(string S) {
        int zero=-1;
        int one=-1;
        int two=-1;
        
        int len=1e9;
        for(int i=0;i<S.length();i++)
        {
            if(S[i]=='0')
            zero=i;
            else if(S[i]=='1')
            one=i;
            else
            two=i;
            
            if(zero!=-1 and one!=-1 and two!=-1)
            {
                int s=min({zero,one,two});
                int e=max({zero,one,two});
                
                len=min(len,e-s+1);
            }
        }
        return len>=1e9 ? -1:len;
    }
};


//METHOD - 2
// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    int smallestSubstring(string S) {
        int zero=0;
        int one=0;
        int two=0;
        
        int i=0;
        int j=0;
        int len=1e9;
        while(j<S.length())
        {
            if(S[j]=='0')
            zero++;
            else if(S[j]=='1')
            one++;
            else
            two++;
            
            j++;
            if(zero>=1 and one>=1 and two>=1)
            len=min(len,j-i);
            while(zero>=1 and one>=1 and two>=1)
            {
                if(S[i]=='0')
                zero--;
                else if(S[i]=='1')
                one--;
                else
                two--;
            
                i++;
                if(zero>=1 and one>=1 and two>=1)
                len=min(len,j-i);
            }
        }
        return len>=1e9 ? -1:len;
    }
};