class Solution {
  public:
  
    int palindrom_length(string s,int l,int r)
    {
        while(l>=0 and r<s.length() and s[l]==s[r])
        {
            l--;
            r++;
        }
        
        return r-l-1;
    }
    
    
    string longestPalin (string S) 
    {
        int maxi=0;
        int index=0;
        for(int i=0;i<S.length();i++)
        {
            int l1=palindrom_length(S,i,i);
            int l2=palindrom_length(S,i,i+1);
            
            l1=max(l1,l2);
            if(l1>maxi)
            {
                maxi=l1;
                index=i-(l1-1)/2;
            }
        }
        
        return S.substr(index,maxi);
    }
};

//time  complexity - O(N^2)
//space complexity - O(1)

