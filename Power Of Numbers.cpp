#define ll long long
class Solution{
    public:
    //You need to coplete this fucntion
    long long helper(long long base,long long n)
    {
        long long ans=1;
        while(n)
        {
            if(n&1)
            {
                n=n-1;
                ans=(ans*base)%1000000007;
            }else
            {
                n/=2;
                base=(base*base)%1000000007;
            }
        }
        return ans;
    }
    
    long long power(int N,int R)
    {
    
       return helper(N,R);
        
    }

};