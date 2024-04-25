
// Time complexity - O(N*M)
// Space complexity- O(1)
class Solution {
  public:
    int findMaxSum(int n, int m, vector<vector<int>> mat) {
        int ans=-1;
        for(int i=0;i<(n-2);i++)
        {
            for(int j=1;j<(m-1);j++)
            {
                int tempSum=0;
                //1st row
                tempSum+=(mat[i][j-1]+mat[i][j]+mat[i][j+1]);
                
                //2nd row
                tempSum+=(mat[i+1][j]);
                
                //3rd row
                tempSum+=(mat[i+2][j-1]+mat[i+2][j]+mat[i+2][j+1]);
                
                ans=max(ans,tempSum);
            }
        }
        return ans;
    }
};