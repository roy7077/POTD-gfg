// Recursion
class Solution {
    public:
    int length(int n)
    {
        int len=0;
        while(n)
        {
            len++;
            n/=10;
        }
        return len;
    }
    bool help(string s,int i,int first,int second)
    {
        //base case
        if(i>=s.length())
        return 0;
        
        //recursive calls
        //and small calculation
        if(first!=-1 and second!=-1)
        {
            int add=first+second;
            int len=length(add);
            int num=0;
            int j=i;
            while(j<s.length() and j<(i+len))
            {
                num*=10;
                num+=(s[j]-'0');
                j++;
            }
            
            if(num!=add)
            return 0;
            
            if(j==s.length())
            return 1;
            
            return help(s,j,second,num);
        }
        
        int num=0;
        for(int j=i;j<s.length();j++)
        {
            num*=10;
            num+=(s[j]-'0');
            
            if(first!=-1)
            {
                bool call=help(s,j+1,first,num);
                if(call)
                return 1;
            }
            else
            {
                bool call=help(s,j+1,num,second);
                if(call)
                return 1;
            }
        }
        return 0;
    }
    bool isAdditiveSequence(string n) {
        return help(n,0,-1,-1);
    }
};
