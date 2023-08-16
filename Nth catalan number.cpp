class Solution
{
    public:
    int mod=1e9+7;
    int findCatalan(int n) 
    {
        vector<long long> v(n+1);
        v[0]=1;
        v[1]=1;
        
        if(n==0 or n==1)
        return n;
        
        for(int k=2;k<=n;k++)
        {
            long long sum=0;
            int i=0;
            int j=k-1;
            
            while(j>=0)
            {
                sum=(sum+(v[i]*v[j])%mod)%mod;
                i++;
                j--;
            }
            
            v[k]=sum;
        }
        
        return v[n];
    }
};