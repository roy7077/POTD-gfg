/* 
  Method - 1
  Iterative
*/
#define ll long long
class Solution {
    public:
    vector<long long> jugglerSequence(long long n) {
        vector<ll> v;
        v.push_back(n);
        while(n!=1)
        {
            if(n&1)
            {
                double temp=sqrt(n);
                n=(temp*temp*temp);
            }
            else
            {
                double temp=sqrt(n);
                n=temp;
            }
            v.push_back(n);
        }
        return v;
    }
};

/* 
  Method - 2
  Recursion
*/
#define ll long long
class Solution {
    public:
    void help(ll& n,vector<ll>& v)
    {
        //base case
        if(n==1)
        return ;
        
        //recursive calls
        //and small calculation
        if(n&1)
        {
            double temp=sqrt(n);
            n=(temp*temp*temp);
        }
        else
        {
            double temp=sqrt(n);
            n=temp;
        }
        v.push_back(n);
        help(n,v);
    }
    vector<long long> jugglerSequence(long long n) {
        vector<ll> v;
        v.push_back(n);
        
        help(n,v);
        return v;
    }
};