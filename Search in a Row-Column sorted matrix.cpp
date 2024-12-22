// Time complexity - O(N+logM + M+logN)
// Space complexity- O(1)
class Solution {
    public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n=mat.size();
        int m=mat[0].size();
        
        // In each row
        for(int i=0;i<n;i++)
        {
            if(mat[i][0]<=x and mat[i][m-1]>=x)
            {
                int s=0;
                int e=m-1;
                while(s<=e)
                {
                    int mid=(s+e)/2;
                    if(mat[i][mid]==x)
                    return 1;
                    else if(mat[i][mid]>x)
                    e=mid-1;
                    else
                    s=mid+1;
                }
            }
        }
        
        // in each coloumn
        for(int j=0;j<m;j++)
        {
            int s=0;
            int e=n-1;
            while(s<=e)
            {
                int mid=(s+e)/2;
                if(mat[mid][j]==x)
                return 1;
                else if(x<mat[mid][j])
                e=mid-1;
                else
                s=mid+1;
            }
        }
        return 0;
    }
};
