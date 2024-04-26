/* 
  1 -> left to right
  2 -> up to down
  3 -> right to left
  4 -> down to up
*/
typedef pair<int,int> pi;
class Solution {
    public:
    pi help(vector<vector<int>>& mat,int i,int j,int dir)
    {
        if(i<0 or i>=mat.size() or j<0 or j>=mat[0].size())
        {
            if(i<0)
            return {0,j};
            else if(i>=mat.size())
            return {i-1,j};
            else if(j<0)
            return {i,j+1};
            else
            return {i,j-1};
        }
        
        if(mat[i][j]==0)
        {
            if(dir==1)
            return help(mat,i,j+1,dir);
            else if(dir==2)
            return help(mat,i+1,j,dir);
            else if(dir==3)
            return help(mat,i,j-1,dir);
            else
            return help(mat,i-1,j,dir);
        }
        
        if(mat[i][j]==1)
        {
            mat[i][j]=0;
            if(dir==1)
            return help(mat,i+1,j,2);
            else if(dir==2)
            return help(mat,i,j-1,3);
            else if(dir==3)
            return help(mat,i-1,j,4);
            else
            return help(mat,i,j+1,1);
        }
    }
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& matrix) {
        pi ans=help(matrix,0,0,1);
        return {ans.first,ans.second};
    }
};