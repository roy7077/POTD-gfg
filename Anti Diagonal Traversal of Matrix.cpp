// Time complexity  - O(N*M)
// Space complexity - O(N*M)
class Solution {
    public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        vector<int> ans;
        //upper part
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            int row=0;
            int col=i;
            while(row<n and col>=0)
            {
                ans.push_back(matrix[row][col]);
                row++;
                col--;
            }
        }
        
        //lower part
        for(int i=1;i<n;i++)
        {
            vector<int> temp;
            int row=i;
            int col=n-1;
            while(row<n and col>=0)
            {
                ans.push_back(matrix[row][col]);
                row++;
                col--;
            }
        }
        
        return ans;
    }
};