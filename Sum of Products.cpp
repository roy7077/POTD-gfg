
// Bit Manipulation
// Time complexity - O(32*N)
// Space complexity- O(1)
#define ll long long
class Solution {
    public:
    long long pairAndSum(int n, long long arr[]) {
        ll sum=0;
        for(int i=0;i<32;i++)
        {
            ll setBit=0;
            for(int j=0;j<n;j++)
            {
                if(arr[j]&(1<<i))
                setBit++;
            }
            sum+=((setBit*(setBit-1))/2)*(1<<i);
        }
        return sum;
    }
};