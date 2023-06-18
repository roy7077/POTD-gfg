class Solution{
    public:
    pair<int,int> endPoints(vector<vector<int>> matrix, int R, int C){
        
        bool left=0;
        bool right=1;
        bool up=0;
        bool down=0;
    
        int i=0;
        int j=0;
        while(1)
        {
            if(j>=C)
            return {i,j-1};
            
            if(i>=R)
            return {i-1,j};
            
            if(i<0)
            return {0,j};
            
            if(j<0)
            return {i,j+1};
            
            if(matrix[i][j]==0)
            {
                if(right)
                j++;
                else if(down)
                i++;
                else if(left)
                j--;
                else if(up)
                i--;
            }
            else
            {
                matrix[i][j]=0;
                if(right)
                {
                    right=0;
                    down=1;
                    i++;
                }
                else if(down)
                {
                    left=1;
                    down=0;
                    j--;
                }
                else if(left)
                {
                    left=0;
                    up=1;
                    i--;
                }
                else
                {
                    up=0;
                    right=1;
                    j++;
                }
            }
            
        }
    }
};