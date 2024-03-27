// Method - 1
// BFS
// Time complexity - O(N*M)
// Space complexity- O((N*M)+(N*M))
class Solution
{
    public:
    int x[4]={-1,0,1,0};
    int y[4]={0,1,0,-1};
    int findShortestPath(vector<vector<int>> &mat)
    {
       //making adj 0
       int n=mat.size();
       int m=mat[0].size();
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<m;j++)
           {
               if(mat[i][j]==0)
               {
                   for(int k=0;k<4;k++)
                   {
                       int r=i+x[k];
                       int c=j+y[k];
                       
                       if(r>=0 and r<n and c>=0 and c<m)
                       mat[r][c]=-1;
                   }
               }
           }
       }
       
       for(auto& v:mat)
       {
           for(auto& it:v)
           {
               if(it==-1)
               it=0;
           }
       }
       
       //finding shortest route from left most shell to right most shell
       queue<pair<int,int>> q;
       vector<vector<int>> visited(n,vector<int>(m,0));
       for(int i=0;i<n;i++)
       {
           if(mat[i][0]==1)
           {
               q.push({i,0});
               visited[i][0]=1;
           }
       }
       
       int cnt=1;
       while(!q.empty())
       {
           int size=q.size();
           while(size--)
           {
               int i=q.front().first;
               int j=q.front().second;
               q.pop();
               
               if(j==m-1)
               return cnt;
                   
               for(int k=0;k<4;k++)
               {
                   int r=i+x[k];
                   int c=j+y[k];
                   
                   if(r>=0 and r<n and c>=0 and c<m and mat[r][c]!=0 and visited[r][c]==0)
                   {
                       q.push({r,c});
                       visited[r][c]=1;
                   }
               }
           }
           cnt++;
       }
       return -1;
    }
};