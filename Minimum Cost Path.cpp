typedef pair<int,pair<int,int>> pi;
class Solution
{
    public:
    int x[4]={-1,0,+1,0};
    int y[4]={0,+1,0,-1};
    int help(vector<vector<int>> grid,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        dis[i][j]=grid[0][0];
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;
        pq.push({grid[0][0],{i,j}});
        
        while(!pq.empty())
        {
            i=pq.top().second.first;
            j=pq.top().second.second;
            int d=pq.top().first;
            pq.pop();
            
            for(int k=0;k<4;k++)
            {
                int r=i+x[k];
                int c=j+y[k];
                
                if(r>=0 and r<n and c>=0 and c<m and dis[r][c]>(d+grid[r][c]))
                {
                    dis[r][c]=d+grid[r][c];
                    pq.push({dis[r][c],{r,c}});
                }
            }
        }
        
        return dis[n-1][m-1];
    }
    
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        int n=grid.size();
        int m=grid[0].size();
        
        vector<vector<int>> dis(n,vector<int>(m,1e9));
        return help(grid,0,0);
    }
};
