#define ll long long 
class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool power(ll base,ll n)
    {
        ll ans=1;
        while(ans<n)
        {
            ans*=2;
            if(ans==n)
            return 1;
        }
        
        if(ans==n)
        return 1;
        
        return 0;
    }
    bool isPowerofTwo(long long n){
        
        return power(2,n);
    }
};
