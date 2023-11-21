// Time complexity - O(N)
// Space complexity- O(height of tree)
class Solution
{
    public:
    bool help(Node* r1,Node* r2)
    {
        //base cases
        if(!r1 and !r2)
        return 1;
        
        if((!r1 and r2) or (r1 and !r2))
        return 0;
        
        if(r1->data!=r2->data)
        return 0;
        
        //recursive calls
        //small calculation
        bool left=help(r1->left,r2->left);
        
        if(!left)
        return 0;
        
        bool right=help(r1->right,r2->right);
        
        return (left and right);
    }
    
    bool isIdentical(Node *r1, Node *r2)
    {
        bool ans=help(r1,r2);
    }
};

