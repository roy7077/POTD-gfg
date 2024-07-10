// Time complexity - O(N*M)
// Space complexity- O(1)
class Solution {
    public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        int maxLen=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j])
                {
                    if(i==0 or j==0)
                    mat[i][j]=1;
                    else 
                    mat[i][j]=min({mat[i-1][j-1],mat[i-1][j],mat[i][j-1]})+1;
                    
                    maxLen=max(maxLen,mat[i][j]);
                }
            }
        }
        return maxLen;
    }
};
