#define ll long long
#define mod 1000000007
class Solution {
  public:
    int nthFibonacci(int n){
        
        ll n1=0;
        ll n2=1;
        
        n--;
        while(n)
        {
            ll a=(n1+n2)%mod;
            n1=n2;
            n2=a;
            n--;
        }
        
        return n2%mod;
    }
};