
class Solution {
  public:
  
    int helper(Node* node)
    {
        //base case
        if(node==NULL)
        return 0;
        
        //recursive calls
        int a=helper(node->left);
        int b=helper(node->right);
        
        int temp=node->data+a+b;
        node->data=a+b;
        
        return temp;
    }
    
    void toSumTree(Node *node)
    {
        int a=helper(node);
        return ;
    }
};

//time complexity  - O(Number of Nodes)
//space complexity - O(Height of tree)