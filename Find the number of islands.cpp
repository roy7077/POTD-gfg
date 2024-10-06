typedef pair<int,int> pi;
class Solution {
    public:
    int x[8]={-1,-1,0,+1,+1,+1,0,-1};
    int y[8]={0,+1,+1,+1,0,-1,-1,-1};
    
    void help(vector<vector<char>>& v,int i,int j,vector<vector<int>>& visited)
    {
        int n=v.size();
        int m=v[0].size();
        
        visited[i][j]=1;
        queue<pi> q;
        q.push({i,j});
        
        while(!q.empty())
        {
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            
            for(int k=0;k<8;k++)
            {
                int nRow=r+x[k];
                int nCol=c+y[k];
                
                if(nRow>=0 and nRow<n and nCol>=0 and nCol<m and v[nRow][nCol]=='1' and !visited[nRow][nCol])
                {
                    visited[nRow][nCol]=1;
                    q.push({nRow,nCol});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> visited(n,vector<int>(m,0));
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' and !visited[i][j])
                {
                    help(grid,i,j,visited);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
