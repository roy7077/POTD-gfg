// Time complexity  - O(N+N+N)
// Space complexity - O(1)
class Solution
{
    public:
    Node* reverse(Node* head)
    {
        //base case
        if(head->next==NULL)
        return head;
        
        Node* temp=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
    
    Node *compute(Node *head)
    {
        Node* rev=reverse(head);
        int maxi=rev->data;
        
        Node* pre=rev;
        Node* h1=rev->next;
        pre->next=NULL;
        while(h1)
        {
            int num=h1->data;
            if(num>=maxi)
            {
                maxi=num;
                pre->next=h1;
                pre=h1;
                h1=h1->next;
                pre->next=NULL;
            }
            else
            {
                Node* temp1=h1->next;
                delete h1;
                h1=temp1;
            }
        }
        
        Node* h2=reverse(rev);
        return h2;
    }
    
};
   