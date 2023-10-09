class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        
        //base case
        if(!node)
        return 0;
        
        //recursive calls
        int left=height(node->left);
        int right=height(node->right);
        
        return max(left,right)+1;
    }
};