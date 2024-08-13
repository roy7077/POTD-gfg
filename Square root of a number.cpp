// Time complexity - O(NlogN)
// Space complexity- O(1)
#define ll long long
class Solution {
  public:
    long long int floorSqrt(long long int n) {
        ll s=0;
        ll e=1e7;
        ll ans=-1;
        while(s<=e)
        {
            ll mid=(s+e)/2;
            if((mid*mid)==n)
            return mid;
            else if((mid*mid)<n)
            {
                s=mid+1;
                ans=mid;
            }
            else
            e=mid-1;
        }
        return ans;
    }
};

