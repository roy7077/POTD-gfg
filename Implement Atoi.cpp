// Time complexity - O(N)
// Space complexity- O(1)
class Solution{
    public:
    int atoi(string s) {
        
        int num=0;
        int i=0;
        if(s[0]=='-')
        i++;
        
        while(i<s.length())
        {
            if(s[i]<'0' or s[i]>'9')
            return -1;
            
            num*=10;
            num+=(s[i]-'0');
            i++;
        }
        
        if(s[0]=='-')
        num*=-1;
        
        return num;
    }
};