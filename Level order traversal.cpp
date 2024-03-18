
/* Method - 1
   BFS 
   Time complexity - O(N)
   SPace complexity- O(N+N)
*/
class Solution
{
    public:
    vector<int> levelOrder(Node* root)
    {
      queue<Node*> q;
      vector<int> ans;
      q.push(root);
      while(!q.empty())
      {
        int size=q.size();
        while(size--)
        {
            Node* node=q.front();
            q.pop();
            
            ans.push_back(node->data);
            
            if(node->left)
            q.push(node->left);
            
            if(node->right)
            q.push(node->right);
        }
      }
      return ans;
    }
};


/* Method - 2
   DFS & map
   Time complexity - O(NlogN)
   SPace complexity- O(N+N+H)
*/
class Solution
{
    public:
    void help(Node* root,map<int,vector<int>>& mp,int h)
    {
        //base case
        if(!root)
        return ;
        
        //recursive calls
        //small calculation
        mp[h].push_back(root->data);
        help(root->left,mp,h+1);
        help(root->right,mp,h+1);
    }
    vector<int> levelOrder(Node* root)
    {
        map<int,vector<int>> mp;
        help(root,mp,0);
        
        vector<int> ans;
        for(auto& it:mp)
        {
            for(auto x:it.second)
            ans.push_back(x);
        }
        return ans;
    }
};