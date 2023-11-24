// Time complexity - O(N*N)
// Space complexity- O(N)
#define ll long long
int mod=1e9+7;
class Solution{
   public:
    vector<long long> nthRowOfPascalTriangle(int n) {
        
        vector<ll> pre={1};
        int i=1;
        while(i<=n)
        {
            vector<ll> curr(i,0);
            curr[0]=1;
            curr[i-1]=1;
            
            int k=0;
            int l=1;
            for(int jj=1;jj<i-1;jj++)
            {
                curr[jj]=(pre[k]+pre[l])%mod;
                k++;
                l++;
            }
            i++;
            pre=curr;
        }
        return pre;
    }
};