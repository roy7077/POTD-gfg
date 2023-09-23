// Time complexity - O(N)
// Space complexity -O(N)
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        
        long long pre[n]={0};
        long long suf[n]={0};
        
        //prefix
        for(int i=0;i<n;i++)
        {
            if(i==0)
            pre[0]=a[0];
            else
            pre[i]=a[i]+pre[i-1];
        }
        
        //suffix
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
            suf[n-1]=a[n-1];
            else
            suf[i]=a[i]+suf[i+1];
        }
        
        for(int i=0;i<n;i++)
        {
            if((pre[i]-a[i])==(suf[i]-a[i]))
            return i+1;
        }
        
        return -1;
    }
};