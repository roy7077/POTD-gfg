class Solution
{
    public:
    vector<int> serialize(Node *root) 
    {
        vector<int> v;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* node=q.front();
            q.pop();
            
            if(node)
            v.push_back(node->data);
            else
            v.push_back(-1);
            
            if(node)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return v;
    }
    
    Node * deSerialize(vector<int> &A)
    {
        Node* root=new Node(A[0]);
        queue<Node*> q;
        q.push(root);
        int i=1;
        
        while(!q.empty() and i<A.size())
        {
            Node* node=q.front();
            q.pop();
            
            bool FR=0;
            bool FL=0;
            if(A[i]==-1)
            {
                node->left=NULL;
                FL=1;
            }
            
            if(A[i+1]==-1)
            {
                node->right=NULL;
                FR=1;
            }
            
            if(!FL)
            {
                Node* newNode1=new Node(A[i]);
                node->left=newNode1;
                q.push(newNode1);
            }
            
            if(!FR)
            {
                Node* newNode1=new Node(A[i+1]);
                node->right=newNode1;
                q.push(newNode1);
            }
            
            i+=2;
        }
        return root;
    }

};