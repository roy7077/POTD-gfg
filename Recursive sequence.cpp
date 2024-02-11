
/* Method - 1
   Iterative
   Time complexity - O(N^2)
   SPace complexity- O(1)
*/
#define ll long long
int mod=1e9+7;
class Solution{
    public:
    long long sequence(int n){
        ll ans=0;
        ll last=1;
        for(int i=1;i<=n;i++)
        {
            ll temp=1;
            for(int j=1;j<=i;j++)
            {
                temp=(temp*last)%mod;
                last++;
            }
            ans=(ans+temp)%mod;
        }
        return ans;
    }
};

/* Method - 2
   Recursion
   Time complexity - O(N^2)
   SPace complexity- O(N)
*/
#define ll long long
int mod=1e9+7;
class Solution{
    public:
    ll help(int n,int i,int& last)
    {
        //base case
        if(i>n)
        return 0;
        
        //recursive calls
        //and small calculation
        ll temp=1;
        for(int j=1;j<=i;j++)
        {
            temp=(temp*last)%mod;
            last++;
        }
        
        return (temp+help(n,i+1,last))%mod;
    }
    long long sequence(int n){
        int last=1;
        return help(n,1,last);
    }
};