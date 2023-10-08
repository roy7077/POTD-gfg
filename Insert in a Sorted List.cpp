// Time complexity - O(N)
// Space complexity- O(N)
class Solution{
    public:
    // Should return head of the modified linked list
    Node* help(Node* head,int data)
    {
        //base case
        if(!head)
        {
            Node* newnode=new Node(data);
            return newnode;
        }
        
        if(head->data>data)
        {
            Node* newnode=new Node(data);
            newnode->next=head;
            return newnode;
        }
        
        //recursive calls
        //small calculation
        Node* temp=help(head->next,data);
        head->next=temp;
        return head;
    }
    Node *sortedInsert(struct Node* head, int data) {
        
        Node* ans=help(head,data);
        return ans;
    }
};
