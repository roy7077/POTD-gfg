
//CPP

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
 

//JAVA

class Solution{
    static int mod=1000000007;
    static long sequence(int n){
        long ans=0;
        long pre=1;
        for(int i=1;i<=n;i++)
        {
            long temp=1;
            for(int j=1;j<=i;j++)
            {
                temp=(temp*pre)%mod;
                pre++;
            }
            ans=(ans+temp)%mod;
        }
        return ans;
    }
}

class Solution{
    static int mod=1000000007;
    static long help(int n,int i,int last)
    {
        //base case
        if(i>n)
        return 0;
        
        //recursive calls
        //and small calculation
        long temp=1;
        for(int j=1;j<=i;j++)
        {
            temp=(temp*last)%mod;
            last++;
        }
        
        return (temp+help(n,i+1,last))%mod;
    }
    static long sequence(int n){
        return help(n,1,1);
    }
}
 

//JAVASCRIPT

class Solution {
    sequence(n)
    {
        let mod=1000000007;
        let ans=0;
        let pre=1;
        for(let i=1;i<=n;i++)
        {
            let temp=1;
            for(let j=1;j<=i;j++)
            {
                temp=(temp*pre)%mod;
                pre++;
            }
            ans=(ans+temp)%mod;
        }
        return ans;
    }
}

// RECURSION
class Solution {
    mod = 1000000007;
    help(n,i,last)
    {
        //base case
        if(i>n)
        return 0;
        
        //recursive calls
        //and small calculation
        let temp=1;
        for(let j=1;j<=i;j++)
        {
            temp=(temp*last)%this.mod;
            last++;
        }
        
        return (temp+this.help(n,i+1,last))%this.mod;
    }
    sequence(n) {
        return this.help(n,1,1);
    }
}