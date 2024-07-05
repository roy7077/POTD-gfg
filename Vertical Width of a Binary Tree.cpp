// Time complexity - O(N)
// Space complexity- O(H)
// BFS
typedef pair<Node*,int> pi;
class Solution {
  public:
    int verticalWidth(Node* root) {
        if(!root)
        return 0;
        
        int mini=1e9;
        int maxi=-1e9;
        
        queue<pi> q;
        q.push({root,0});
        
        while(!q.empty())
        {
            Node* node=q.front().first;
            int ind=q.front().second;
            q.pop();
            
            mini=min(mini,ind);
            maxi=max(maxi,ind);
            
            if(node->left)
            q.push({node->left,ind-1});
            
            if(node->right)
            q.push({node->right,ind+1});
        }
        return maxi-mini+1;
    }
};