// Time complexity - O(NlogN)
// Space complexity- O(N)
#define ll long long
typedef pair<ll,ll> pi;
class Solution {
    public:
    static bool cmp(pi& a,pi& b)
    {
        return a.first>b.first;
    }
    
    long long maxTip(int n, int x, int y, vector<int> &arr, vector<int> &brr) {
        
        vector<pi> v;
        for(int i=0;i<n;i++)
        v.push_back({arr[i]-brr[i],i});
        
        sort(v.begin(),v.end(),cmp);
        int i=0;
        ll sum1=0;
        ll sum2=0;
        
        while(i<n and (x or y))
        {
            if(v[i].first>=0)
            {
                if(x)
                {
                    sum1+=arr[v[i].second];
                    x--;
                }
                else
                {
                    sum2+=brr[v[i].second];
                    y--;
                }
            }
            else
            {
                
                if(y)
                {
                    sum2+=brr[v[i].second];
                    y--;
                }
                else if(x)
                {
                    sum1+=arr[v[i].second];
                    x--;
                }
                
                // if(y>=n-i)
                // {
                //     sum2+=brr[v[i].second];
                //     y--;
                // }
                // else
                // {
                //     sum1+=arr[v[i].second];
                //     x--;
                // }
            }
            i++;
        }
        
        return sum1+sum2;
        
        // vector<pi> a;
        // vector<pi> b;
        
        // for(int i=0;i<n;i++)
        // {
        //     a.push_back({arr[i],i});
        //     b.push_back({brr[i],i});
        // }
        
        // //sort both vectors
        // sort(a.begin(),a.end(),cmp);
        // sort(b.begin(),b.end(),cmp);
        
        // //selecting maximum elements and 
        // //marking the index
        // unordered_map<ll,ll> mp;
        // ll sum1=0;
        // ll sum2=0;
        
        // int i=0;
        // int j=0;
        
        // int cnt1=0;
        // int cnt2=0;
        
        // while(i<n and j<n and cnt1<x and cnt2<y)
        // {
        //     if(a[i].first>b[j].first)
        //     {
        //         if(mp.count(a[i].second))
        //         {
        //             i++;
        //             continue;
        //         }
                
        //         sum1+=a[i].first;
        //         mp[a[i].second]=1;
        //         cnt1++;
        //         i++;
        //     }
        //     else
        //     {
        //         if(mp.count(b[j].second))
        //         {
        //             j++;
        //             continue;
        //         }
                
        //         sum2+=b[j].first;
        //         mp[b[j].second]=1;
        //         cnt2++;
        //         j++;
        //     }
        // }
        
        // //add in 1st
        // while(cnt1<x and i<n)
        // {
        //     if(mp.count(a[i].second))
        //     {
        //         i++;
        //         continue;
        //     }
            
        //     sum1+=a[i].first;
        //     mp[a[i].second]=1;
        //     cnt1++;
        //     i++;
        // }
        
        // //add in second
        // while(cnt2<y and j<n)
        // {
        //     if(mp.count(b[j].second))
        //     {
        //         j++;
        //         continue;
        //     }
            
        //     sum2+=b[j].first;
        //     mp[b[j].second]=1;
        //     cnt2++;
        //     j++;
        // }
        
        // return sum1+sum2;
    }
};

// -4 -2 0 2 4
// 4 2 0 -2 -4


