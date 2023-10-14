class Solution
{
    public:
    //Function to perform in-order traversal and store nodes in vector 
    void inOrder(Node* root, vector<int>& nodes){
        if(!root)
            return;
        
        inOrder(root->left, nodes);
        nodes.push_back(root->data);
        inOrder(root->right, nodes);
    }
    
    //Function to find the nodes that are common in both BST. 
    vector <int> findCommon(Node *root1, Node *root2)
    {
        vector<int> nodes1, nodes2, commonNodes;
        
        inOrder(root1, nodes1);
        inOrder(root2, nodes2);
        
        int i = 0,j = 0;
        
        while(i < nodes1.size() && j < nodes2.size()){
            if(nodes1[i] == nodes2[j]){
                commonNodes.push_back(nodes1[i]);
                i++;
                j++;
            } else if(nodes1[i] < nodes2[j]){
                i++;
            } else{
                j++;
            }
        }
        
        return commonNodes;
    }
};