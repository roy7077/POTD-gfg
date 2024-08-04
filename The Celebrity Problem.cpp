class Solution {
    public:
    int celebrity(vector<vector<int> >& mat) {
        
        int n=mat.size();
        int m=mat[0].size();
        vector<int> col(m,0);
        
        for(int j=0;j<m;j++)
        {
            int cnt=0;
            for(int i=0;i<n;i++)
            {
                if(i==j and mat[i][j])
                {
                    cnt=0;
                    break;
                }
                
                cnt+=mat[i][j];
            }
            col[j]=cnt;
        }
        
        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<m;j++)
            cnt+=mat[i][j];
            
            if(cnt==0 and col[i]==n-1)
            return i;
        }
        
        return -1;
    }
};

