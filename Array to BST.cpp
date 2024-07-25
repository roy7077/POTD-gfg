/*
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val)
        : data(val)
        , left(nullptr)
        , right(nullptr) {}
};
*/

// Time complexity - O(N)
// Space complexity- O(Height of the tree)
class Solution {
    public:
    Node* help(vector<int>& nums,int s,int e)
    {
        //base case
        if(s>e)
        return NULL;
        
        //recursive calls
        //and small calculation
        int mid=(s+e)/2;
        Node* root=new Node(nums[mid]);
        root->left=help(nums,s,mid-1);
        root->right=help(nums,mid+1,e);
        return root;
    }
    Node* sortedArrayToBST(vector<int>& nums) {
        return help(nums,0,nums.size()-1);
    }
};
