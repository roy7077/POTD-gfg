class Solution 
{
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> visited(N,vector<int>(M,0));
        q.push({0,{0,0}});
        visited[0][0]=1;
        
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            
            int x=it.second.first;
            int y=it.second.second;
            int s=it.first;
            
            if(x==X and y==Y)
            return s;
            
            if(x-1>=0 and A[x-1][y]==1 and visited[x-1][y]==0)
            {
                q.push({s+1,{x-1,y}});
                visited[x-1][y]=1;
            }
            
            if(x+1<N and A[x+1][y]==1 and visited[x+1][y]==0)
            {
                q.push({s+1,{x+1,y}});
                visited[x+1][y]=1;
            }
            
            if(y+1<M and A[x][y+1]==1 and visited[x][y+1]==0)
            {
                q.push({s+1,{x,y+1}});
                visited[x][y+1]=1;
            }
            
            if(y-1>=0 and A[x][y-1]==1 and visited[x][y-1]==0)
            {
                q.push({s+1,{x,y-1}});
                visited[x][y-1]=1;
            }
        }
        
        return -1;
    }
};

