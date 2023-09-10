class Solution
{
       public:
        
        Node* help(Node* root,int& data)
        {
            if(root->data>data)
            {
                if(root->left)
                return help(root->left,data);
                else
                return root->left=new Node(data);
            }
            else if(root->data<data)
            {
                if(root->right)
                return help(root->right,data);
                else
                return root->right=new Node(data);
            }
            else
            return root;
        }
        
        Node* insert(Node* node, int data) {
        
            return help(node,data);
        }

};