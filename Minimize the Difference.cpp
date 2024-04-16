// Method - 1
// Prefix array & suffix array
// Time complexity - O(N)
// Space complexity- O(N+N)
#define ll long long
class Solution {
    public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
       vector<ll> pre(n,0);
       vector<ll> suf(n,0);
      
       // / -> min
       // % -> max
       ll MAX=1e9+3;
       
       //prefix
       pre[0]=(MAX*arr[0])+arr[0];
       for(int i=1;i<n;i++)
       {
           ll back_min=pre[i-1]/MAX;
           ll back_max=pre[i-1]%MAX;
           
           ll mini;
           ll maxi;
           if(arr[i]<back_min)
           mini=arr[i];
           else
           mini=back_min;
           
           if(arr[i]>back_max)
           maxi=arr[i];
           else
           maxi=back_max;
           
           pre[i]=(MAX*mini)+maxi;
       }
       
       //suffix
       suf[n-1]=(MAX*arr[n-1])+arr[n-1];
       for(int i=n-2;i>=0;i--)
       {
           ll back_min=suf[i+1]/MAX;
           ll back_max=suf[i+1]%MAX;
           
           ll mini;
           ll maxi;
           
           if(arr[i]<back_min)
           mini=arr[i];
           else
           mini=back_min;
           
           if(arr[i]>back_max)
           maxi=arr[i];
           else
           maxi=back_max;
           
           suf[i]=(MAX*mini)+maxi;
       }
       
       
       int i=0;
       int j=k-1;
       ll ans=1e9;
       
       ans=suf[k]%MAX - suf[k]/MAX;
       while(j+2<n)
       {
           i++;
           j++;
           
           int maximum;
           int minimum;
           
           if((pre[i-1]%MAX)>(suf[j+1]%MAX))
           maximum=pre[i-1]%MAX;
           else
           maximum=suf[j+1]%MAX;
           
           
           if((pre[i-1]/MAX)<(suf[j+1]/MAX))
           minimum=pre[i-1]/MAX;
           else
           minimum=suf[j+1]/MAX;
           
           if((maximum-minimum)<ans)
           ans=maximum-minimum;
           
       }
       
       if((pre[n-k-1]%MAX - pre[n-k-1]/MAX)<ans)
       ans=(pre[n-k-1]%MAX - pre[n-k-1]/MAX);
       
       return ans;
    }
};

// Method - 2
// pre calculation & suffix array
// Time complexity - O(N)
// Space complexity- O(N)
#define ll long long
class Solution {
    public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
       
       vector<ll> suf(n,0);
      
       // / -> min
       // % -> max
       ll MAX=1e9+3;
       
       //suffix
       suf[n-1]=(MAX*arr[n-1])+arr[n-1];
       for(int i=n-2;i>=0;i--)
       {
           ll back_min=suf[i+1]/MAX;
           ll back_max=suf[i+1]%MAX;
           
           ll mini;
           ll maxi;
           
           if(arr[i]<back_min)
           mini=arr[i];
           else
           mini=back_min;
           
           if(arr[i]>back_max)
           maxi=arr[i];
           else
           maxi=back_max;
           
           suf[i]=(MAX*mini)+maxi;
       }
       
       
      
       int pre_min=arr[0];
       int pre_max=arr[0];
       int i=0;
       int j=k-1;
       ll ans=suf[k]%MAX - suf[k]/MAX;
       while(j+2<n)
       {
           i++;
           j++;
           
           int maximum;
           int minimum;
           
           if(pre_max>(suf[j+1]%MAX))
           maximum=pre_max;
           else
           maximum=suf[j+1]%MAX;
           
           
           if(pre_min<(suf[j+1]/MAX))
           minimum=pre_min;
           else
           minimum=suf[j+1]/MAX;
           
           if((maximum-minimum)<ans)
           ans=maximum-minimum;
           
           if(arr[i]<pre_min)
           pre_min=arr[i];
           
           if(arr[i]>pre_max)
           pre_max=arr[i];
           
       }
       
       if((pre_max - pre_min)<ans)
       ans=pre_max-pre_min;
       
       return ans;
    }
};