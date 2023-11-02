// Time complexity - O(N)
// Space complexity- O(1)
class Solution{
    public:
    int minDist(int a[], int n, int x, int y) {
        
        int i=-1;
        int j=-1;
        int ans=1e9;
        
        for(int k=0;k<n;k++)
        {
            if(a[k]==x)
            i=k;
            
            if(a[k]==y)
            j=k;
            
            if(i!=-1 and j!=-1)
            ans=min(ans,abs(i-j));
        }
        
        if(ans>=1e9)
        return -1;
        
        return ans;
    }
};
