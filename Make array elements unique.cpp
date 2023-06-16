#define ll long long
class Solution {
  public:
    
    long long int minIncrements(vector<int> a, int n) {
        
        sort(a.begin(),a.end());
        map<int,int> mp;
        mp[a[0]]=1;
        
        ll cnt=0;
        for(int i=1;i<n;i++)
        {
            if(mp.count(a[i])!=0)
            {
                int temp=a[i];
                a[i]=a[i-1]+1;
                cnt+=a[i]-temp;
            }
            
            mp[a[i]]++;
        }
        
        return cnt;
    }
};
// Expected Time Complexity: O(N*log(N))
// Expected Auxiliary Space: O(N)