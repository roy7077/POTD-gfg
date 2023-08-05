class Solution{
    public:
    
    long long findMinDiff(vector<long long> a, long long n, long long m)
    {
        sort(a.begin(),a.end());
        long long ans=1e9;
        long long i=0;
        long long j=m-1;
        
        while(j<n)
        {
            ans=min(ans,a[j]-a[i]);
            i++;
            j++;
        }
        
        return ans;
    }   
};