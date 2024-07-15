// Recursion
class Solution {
    public:
    bool help(int& s,int& d,int num,int sum,int len,int& ans)
    {
        //base case
        if(len==d and sum==s)
        {
            ans=num;
            return 1;
        }
        
        if(len>d or sum>s)
        return 0;
        
        //recursive calls
        //and small calculation
        for(int i=0;i<=9;i++)
        {
            if(len==0 and i==0)
            continue;
            
            num*=10;
            num+=i;
            bool fnCall=help(s,d,num,sum+i,len+1,ans);
            if(fnCall)
            return 1;
            
            num/=10;
        }
        return 0;
    }
    string smallestNumber(int s, int d) {
        int ans=0;
        bool fnCall=help(s,d,0,0,0,ans);
        if(!ans)
        return "-1";
        
        return to_string(ans);
    }
};
