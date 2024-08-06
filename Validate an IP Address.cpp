/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */


class Solution {
    public:
        int isValid(string s) {
            
            int cnt=0;
            int num=0;
            int zero=0;
            int number=0;
            
            for(auto it:s)
            {
                if(it!='.')
                {
                    if(it<'0' or it>'9')
                    return 0;
                    
                    if(num==0 and it=='0')
                    zero++;
                    
                    num*=10;
                    num+=(it-'0');
                    number++;
                    
                }
                else
                {
                    
                    if(number>0 and zero>0 and number!=zero)
                    return 0;
                    // if(cnt==0 and num==0)
                    // return 0;
                    //cout<<num<<" ";
                    if(num<0 or num>255 or zero>1 or number==0)
                    return 0;
                    
                    number=0;
                    zero=0;
                    num=0;
                    cnt++;
                }
            }
            if(number>0 and zero>0 and number!=zero)
            return 0;
                    
            if(num<0 or num>255 or zero>1 or number==0)
            return 0;
                    
            if(num<0 or num>255)
            return 0;
            
            if(cnt==3)
            return 1;
            else
            return 0;
        }
};

