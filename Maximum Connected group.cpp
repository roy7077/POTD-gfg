class Disjoinset{
    public:
    vector<int> parent;
    vector<int> size;
    
    // constructor
    Disjoinset(int n)
    {
        parent.resize(n+1,0);
        size.resize(n+1,1);
        
        for(int i=0;i<=n;i++)
        parent[i]=i;
    }
    
    // find ultimate parent
    int Up(int a)
    {
        if(parent[a]==a)
        return a;
        
        return parent[a]=Up(parent[a]);
    }
    
    // union
    void unionBySize(int a,int b)
    {
        int Upa=Up(a);
        int Upb=Up(b);
        
        if(Upa==Upb)
        return ;
        
        if(size[Upa]>size[Upb])
        {
            parent[Upb]=Upa;
            size[Upa]+=size[Upb];
        }
        else
        {
            parent[Upa]=Upb;
            size[Upb]+=size[Upa];
        }
    }
};

class Solution {
    public:
    int x[4]={-1,0,+1,0};
    int y[4]={0,+1,0,-1};
    
    int MaxConnection(vector<vector<int>>& grid) {
        
        int n=grid.size();
        int m=grid[0].size();
      
        Disjoinset ds(n*m+1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                continue;
                
                int ind1=(i*m)+j;
                for(int k=0;k<4;k++)
                {
                    int r=i+x[k];
                    int c=j+y[k];
                    int ind2=(r*m)+c;
                    
                    if(r>=0 and r<n and c>=0 and c<m and grid[r][c])
                    ds.unionBySize(ind1,ind2);
                }
            }
        }
        
        int maxSize=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                continue;
                
                set<int> st;
                for(int k=0;k<4;k++)
                {
                    int r=i+x[k];
                    int c=j+y[k];
                    
                    if(r>=0 and r<n and c>=0 and c<m)
                    {
                        if(grid[r][c])
                        st.insert(ds.Up(r*m+c));
                    }
                }
                
                int size=1;
                for(auto& it:st)
                size+=ds.size[it];
                
                maxSize=max(maxSize,size);
            }
        }
        
        maxSize=max(maxSize,ds.size[ds.Up(0)]);
        return maxSize;
    }
};
