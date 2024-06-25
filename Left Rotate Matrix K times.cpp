// Time complexity - O(N*M)
// Space complexity- O(M)
class Solution {
    public:
    vector<vector<int>> rotateMatrix(int k, vector<vector<int>> mat) {
        int n=mat.size();
        int m=mat[0].size();
        k%=m;
        for(int i=0;i<n;i++)
        {
            vector<int> temp;
            for(int j=0;j<k;j++)
            temp.push_back(mat[i][j]);
            
            int l=0;
            for(int j=k;j<m;j++)
            {
                mat[i][l]=mat[i][j];
                l++;
            }
            
            int leftLen=m-k;
            l=0;
            for(int j=leftLen;j<m;j++)
            {
                mat[i][j]=temp[l];
                l++;
            }
        }
        
        return mat;
    }
};