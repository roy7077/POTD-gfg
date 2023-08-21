class Solution {
public:
    int Count(vector<vector<int> >& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]==0)
                continue;
                
                int sum=0;
                bool flag=0;
                for(int r=-1;r<=1;r++)
                {
                    for(int c=-1;c<=1;c++)
                    {
                        if(r==0 and c==0)
                        continue;
                        
                        int delr=i+r;
                        int delc=j+c;
                        
                        if(delr>=0 and delr<n and delc>=0 and delc<m and matrix[delr][delc]==0)
                        {
                            sum++;
                            flag=1;
                        }
                    }
                }

                if(flag and sum%2==0)
                cnt++;
            }
        }
        
        return cnt;
    }
};
