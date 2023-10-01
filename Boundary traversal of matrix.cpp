// Time complexity - O(2*(N+M))
// Space complexity- O(2*(N+M))
class Solution
{   
    public:
    //Function to return list of integers that form the boundary 
    //traversal of the matrix in a clockwise manner.
    vector<int> boundaryTraversal(vector<vector<int> > matrix, int n, int m) 
    {
        vector<int> ans;
        
        //1st row
        for(int i=0;i<m;i++)
        ans.push_back(matrix[0][i]);
        
        //last col
        for(int i=1;i<n;i++)
        ans.push_back(matrix[i][m-1]);
        
        if(n>1)
        {
            //last row
            for(int i=m-2;i>=0;i--)
            ans.push_back(matrix[n-1][i]);
        }
        
        
        //1st col
        if(m>1)
        {
            for(int i=n-2;i>=1;i--)
            ans.push_back(matrix[i][0]);
        }
        
        return ans;
    }
};