
/*-------------BFS------------------*/

class Solution {
    public:
    int dx[4] = { -1 ,0 ,0, 1};
    int dy[4] = { 0, -1, 1, 0};
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> pq;
        
        //1st and last row
        for(int i=0;i<m;i++)
        {
            //1st row
            if(grid[0][i])
            {
                pq.push({0,i});
                visited[0][i]=1;
            }
            
            //last row
            if(grid[n-1][i])
            {
                pq.push({n-1,i});
                visited[n-1][i]=1;
            }
        }
        
        //1st and last col
        for(int i=0;i<n;i++)
        {
            //1st col
            if(grid[i][0])
            {
                pq.push({i,0});
                visited[i][0]=1;
            }
            
            //last col
            if(grid[i][m-1])
            {
                pq.push({i,m-1});
                visited[i][m-1]=1;
            }
        }
        
        while(!pq.empty())
        {
            auto it=pq.front();
            pq.pop();
            int x=it.first;
            int y=it.second;
            
            for(int i=0;i<5;i++)
            {
                int row=x+dx[i];
                int col=y+dy[i];
                
                if(row<n and row>=0 and col<m and col>=0 and !visited[row][col] and grid[row][col])
                {
                    visited[row][col]=1;
                    pq.push({row,col});
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] and grid[i][j])
                cnt++;
            }
        }
        
        return cnt;
    }
};
 

/*------------------------DFS-------------------------*/


class Solution {
    public:
    int dx[4] = { -1 ,0 ,0, 1};
    int dy[4] = { 0, -1, 1, 0};
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> pq;
        
        //1st and last row
        for(int i=0;i<m;i++)
        {
            //1st row
            if(grid[0][i])
            {
                pq.push({0,i});
                visited[0][i]=1;
            }
            
            //last row
            if(grid[n-1][i])
            {
                pq.push({n-1,i});
                visited[n-1][i]=1;
            }
        }
        
        //1st and last col
        for(int i=0;i<n;i++)
        {
            //1st col
            if(grid[i][0])
            {
                pq.push({i,0});
                visited[i][0]=1;
            }
            
            //last col
            if(grid[i][m-1])
            {
                pq.push({i,m-1});
                visited[i][m-1]=1;
            }
        }
        
        while(!pq.empty())
        {
            auto it=pq.front();
            pq.pop();
            int x=it.first;
            int y=it.second;
            
            for(int i=0;i<5;i++)
            {
                int row=x+dx[i];
                int col=y+dy[i];
                
                if(row<n and row>=0 and col<m and col>=0 and !visited[row][col] and grid[row][col])
                {
                    visited[row][col]=1;
                    pq.push({row,col});
                }
            }
        }
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(!visited[i][j] and grid[i][j])
                cnt++;
            }
        }
        
        return cnt;
    }
};