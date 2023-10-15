class Solution{
    
    public:
    // Your are required to complete this function
    // function should return root of the modified BST
    
    void inorder(Node* root,vector<int>& v)
    {
        //base case
        if(!root)
        return ;
        
        inorder(root->left,v);
        v.push_back(root->data);
        inorder(root->right,v);
    }
    
    Node* makeBst(int s,int e,vector<int>& v)
    {
        //base case
        if(s>e)
        return NULL;
        
        int mid=(s+e)/2;
        Node* newnode=new Node(v[mid]);
        newnode->left=makeBst(s,mid-1,v);
        newnode->right=makeBst(mid+1,e,v);
    }
    
    Node* buildBalancedTree(Node* root)
    {
    	vector<int> v;
    	inorder(root,v);
    	
    	Node* head=makeBst(0,v.size()-1,v);
    	return head;
    }
};
