// Time complexity - O(N)
// Space complexity- O(1)
#define ll long long
class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        ll start = -1;
        ll end = -1;
        ll count = 0;
        
        for(int i = 0; i < n; i++) 
        {
            if(a[i] > R) {
                start = i;
                end = i;
                continue;
            }
            
            if(a[i] >= L) {
                end = i;
            }
            
            count += (end - start);
        }
        
        return count;
    }
};
