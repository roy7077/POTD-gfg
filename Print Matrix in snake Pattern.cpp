
// Time complexity - O(N*M)
// Space complexity- O(N*M)
class Solution
{   
    public:
    //Function to return list of integers visited in snake pattern in matrix.
    vector<int> snakePattern(vector<vector<int> > matrix)
    {   
       int n=matrix.size();
       int m=matrix[0].size();
       vector<int> ans;
       bool flag=1;
       for(int i=0;i<n;i++)
       {
           if(flag)
           {
               for(int j=0;j<m;j++)
               ans.push_back(matrix[i][j]);
           }
           else
           {
               for(int j=m-1;j>=0;j--)
               ans.push_back(matrix[i][j]);
           }
           flag=(!flag);
       }
       return ans;
    }
};