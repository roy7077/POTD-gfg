
class Solution
{
    public:
    int mini=-1e9;
    int maxi=1e9;
    
    void print(Node* root,int key,Node*& pre,Node*& suc)
    {
        if(root==NULL)
        return ;
        
        if(root->key<key and root->key>mini)
        {
            mini=root->key;
            pre=root;
        }
        
        if(root->key>key and root->key<maxi)
        {
            maxi=root->key;
            suc=root;
        }
        
        print(root->left,key,pre,suc);
        print(root->right,key,pre,suc);
        
    }
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        mini=-1e9;
        maxi=1e9;
        
        print(root,key,pre,suc);
    }
};

// time complexity - O(number of nodes)
// space complexity - O(height of a tree)