/*----------TWO APPROACHES--------*/

/*--------Method-1-------------*/
// Time complexity - O(N)
// Space complexity- O(N+N)
#define ll long long
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        vector<ll> pre(n,0);
        vector<ll> suff(n,0);
        
        ll sum=0;
        for(int i=n-1;i>=0;i--)
        {
            if(sum<0)
            sum=0;
            
            if(sum<0)
            suff[i]=0;
            else
            suff[i]=sum;
            
            sum+=a[i];
        }
        
        sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum<0)
            sum=0;
            
            if(sum<0)
            pre[i]=0;
            else
            pre[i]=sum;
            
            sum+=a[i];
        }

        sum=0;
        ll maxi=-1e9;
        for(int i=0;i<k;i++)
        sum+=a[i];
        
        maxi=max(sum,maxi);
        int i=0;
        int j=k;
        while(j<n)
        {
            sum-=a[i];
            sum+=a[j];
            i++;
            
            ll temp=sum;
            if(pre[i]>0)
            temp+=pre[i];
            
            if(suff[j]>0)
            temp+=suff[j];
            
            maxi=max(temp,maxi);
            j++;
        }
        return maxi;
    }
};


/*--------Method-2-------------*/
// Time complexity - O(N)
// Space complexity- O(N)
#define ll long long
class Solution{
    public:    
    long long int maxSumWithK(long long int a[], long long int n, long long int k) 
    {
        ll maxnum=1e9;
        vector<ll> store(n,0);
        ll sum=0;
        for(int i=n-1;i>=0;i--)
        {
            if(sum<0)
            sum=0;
            
            if(sum<0)
            store[i]=0;
            else
            store[i]=sum;
            
            sum+=a[i];
        }
        
        sum=0;
        for(int i=0;i<n;i++)
        {
            if(sum<0)
            sum=0;
            
            if(sum<0)
            {
                ll original=store[i];
                store[i]=(0*maxnum)+original;
            }
            else
            {
                ll original=store[i];
                store[i]=(sum*maxnum)+original;
            }
            
            sum+=a[i];
        }

        sum=0;
        ll maxi=-1e9;
        for(int i=0;i<k;i++)
        sum+=a[i];
        
        maxi=max(sum,maxi);
        int i=0;
        int j=k;
        while(j<n)
        {
            sum-=a[i];
            sum+=a[j];
            i++;
            
            ll temp=sum;
            if((store[i]/maxnum)>0)
            temp+=store[i]/maxnum;
            
            
            
            if((store[j]%maxnum)>0)
            temp+=store[j]%maxnum;
            
            maxi=max(temp,maxi);
            j++;
        }
        return maxi;
    }
};