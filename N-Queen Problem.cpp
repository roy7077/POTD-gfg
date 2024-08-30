class Solution{
    public:
    bool isValid(vector<vector<int>>& v,int i,int j)
    {
        int n=v.size();
        int m=v[0].size();
        
        // same row
        for(int k=0;k<m;k++)
        {
            if(v[i][k])
            return 0;
        }
        
        
        // same col
        for(int k=0;k<n;k++)
        {
            if(v[k][j])
            return 0;
        }
        
        // check left to right diagnoal
        int row=i;
        int col=j;
        while(row>=0 and col>=0)
        {
            if(v[row][col])
            return 0;
            
            row--;
            col--;
        }
        
        // check right to left diagonal
        row=i;
        col=j;
        while(row>=0 and col<m)
        {
            if(v[row][col])
            return 0;
            
            row--;
            col++;
        }
        
        return 1;
    }
    
    void help(vector<vector<int>>& v,int row,vector<vector<int>>& ans)
    {
        // base case
        if(row>=v.size())
        {
            vector<int> temp;
            for(int i=0;i<v.size();i++)
            {
                for(int j=0;j<v[0].size();j++)
                {
                    if(v[i][j])
                    {
                        temp.push_back(j+1);
                        break;
                    }
                }
            }
            ans.push_back(temp);
            return ;
        }
        
        // recursive calls
        // and small calculation
        for(int col=0;col<v[0].size();col++)
        {
            if(isValid(v,row,col))
            {
                v[row][col]=1;
                help(v,row+1,ans);
                v[row][col]=0;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        vector<vector<int>> chessBoard(n,vector<int>(n,0));
        
        help(chessBoard,0,ans);
        return ans;
    }
};
