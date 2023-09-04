// Expected Time Complexity: O(4*n*m)
// Expected Auxiliary Space: O(2*n*m)

class Solution{
    public:
    
    int r[4]={-1, 0, 1, 0};
    int c[4]={0, 1, 0, -1};
    void dfs(vector<vector<char>>& mat,int i,int j,vector<vector<int>>& visited)
    {
        int n=mat.size();
        int m=mat[0].size();
        visited[i][j]=1;
        for(int k=0;k<4;k++)
        {
            int delr=i+r[k];
            int delc=j+c[k];
            
            if(delr>=0 and delr<n and delc>=0 and delc<m and mat[delr][delc]=='O' and !visited[delr][delc])
            dfs(mat,delr,delc,visited);
        }
    }
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        //first row and last row
        for(int i=0;i<m;i++)
        {
            //first row
            if(mat[0][i]=='O')
            dfs(mat,0,i,visited);
            
            //last row
            if(mat[n-1][i]=='O')
            dfs(mat,n-1,i,visited);
        }
        
        //first col and last col
        for(int i=0;i<n;i++)
        {
            //first col
            if(mat[i][0]=='O')
            dfs(mat,i,0,visited);
            
            //last col
            if(mat[i][m-1]=='O')
            dfs(mat,i,m-1,visited);
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==0 and mat[i][j]=='O')
                mat[i][j]='X';
            }
        }
        
        return mat;
    }
};