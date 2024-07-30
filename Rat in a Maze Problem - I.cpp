class Solution {
    public:
    void help(vector<vector<int>>& arr,int i,int j,string s,vector<vector<int>>& visited,vector<string>& ans)
    {
        // base case
        int n=arr.size();
        int m=arr[0].size();
        
        if(i<0 or i>=n or j<0 or j>=m or !arr[i][j] or visited[i][j])
        return ;
        
        if(i==n-1 and j==m-1)
        {
            ans.push_back(s);
            return ;
        }
        
        // recursive calls
        // and small calculation
        visited[i][j]=1;
    
        help(arr,i-1,j,s+'U',visited,ans);
        help(arr,i,j+1,s+'R',visited,ans);
        help(arr,i+1,j,s+'D',visited,ans);
        help(arr,i,j-1,s+'L',visited,ans);
        
        visited[i][j]=0;
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<string> ans;
        vector<vector<int>> visited(mat.size(),vector<int>(mat[0].size(),0));
        string s="";
        help(mat,0,0,s,visited,ans);
        
        return ans;
    }
};
