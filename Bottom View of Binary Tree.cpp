// Time complexity - O(Number of nodes)
// Space complexity- O(width of tree*2)
typedef pair<Node*,int> pi;
class Solution {
    public:
    vector<int> bottomView(Node *root) {
        map<int,Node*> mp;
        queue<pi> q;
        q.push({root,0});
        
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                auto it=q.front();
                Node* node=it.first;
                int dir=it.second;
                q.pop();
                
                mp[dir]=node;
                
                if(node->left) 
                q.push({node->left,dir-1});
                
                if(node->right)
                q.push({node->right,dir+1});
            }
        }
        
        vector<int> ans;
        for(auto& it:mp)
        ans.push_back(it.second->data);
        
        return ans;
    }
};

