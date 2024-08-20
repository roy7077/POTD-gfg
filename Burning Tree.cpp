// Time complexity - O(N)
// Space complexity- O(H*3)
class Sagar{
    public:
    bool isFound=0;
    int height=0;
    int ans=0;
    
    Sagar(){
        isFound=0;
        height=0;
        ans=0;
    }
};


class Solution {
    public:
    Sagar help(Node* root,int& target)
    {
        // base case
        if(!root)
        {
            Sagar temp;
            return temp;
        }
        
        // recursive calls
        // and small calculation
        Sagar left=help(root->left,target);
        Sagar right=help(root->right,target);
        
        // if current node is our target node
        if(root->data==target)
        {
            Sagar temp;
            temp.height=1;
            temp.ans=max(left.height,right.height);
            temp.isFound=1;
            return temp;
        }
        
        // if current node is not targeted node
        if(left.isFound)
        {
            Sagar temp;
            temp.height=left.height+1;
            temp.isFound=1;
            temp.ans=max({left.ans,right.ans,left.height+right.height});
            return temp;
        }
        
        if(right.isFound)
        {
            Sagar temp;
            temp.height=right.height+1;
            temp.isFound=1;
            temp.ans=max({left.ans,right.ans,left.height+right.height});
            return temp;
        }
        
        Sagar temp;
        temp.isFound=0;
        temp.height=max(left.height,right.height)+1;
        return temp;
    }
    int minTime(Node* root, int target) 
    {
        Sagar ans=help(root,target);
        return ans.ans;
    }
};
