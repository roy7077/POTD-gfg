class four{
    public:
    int maxi=-1e9;
    int mini=1e9;
    int size=0;
    bool isbst=1;
};

class Solution{
    public:
    four help(Node* root)
    {
        //base case
        if(!root)
        {
            four f;
            return f;
        }
        
        //recursive calls
        //small calculation
        four a=help(root->left);
        four b=help(root->right);
        
        if(root->data>a.maxi and root->data<b.mini and a.isbst and b.isbst)
        {
            four f;
            f.maxi=max({b.maxi,a.maxi,root->data});
            f.mini=min({a.mini,b.mini,root->data});
            f.size=a.size+b.size+1;
            return f;
        }
        
        four f;
        f.size=max(a.size,b.size);
        f.mini=min(root->data,a.mini);
        f.maxi=max(root->data,b.maxi);
        f.isbst=0;
        return f;
    }
    int largestBst(Node *root)
    {
    	four ans=help(root);
    	return ans.size;
    }
};

