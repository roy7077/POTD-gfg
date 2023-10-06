// Time complexity - O(N)
// Space complexity- O(1)
class Solution
{
    public:
    Node* reverse(Node* head)
    {
        //base case
        if(head->next==NULL)
        return head;
        
        //recursive calls
        Node* temp=reverse(head->next);
        head->next->next=head;
        head->next=NULL;
        return temp;
    }
    void rearrange(struct Node *odd)
    {
        if(odd==NULL or odd->next==NULL)
        return ;
        
        Node* head1,*head2,*h1,*h2;
        head1=h1=odd;
        head2=h2=odd->next;
        
        while(h2 and h2->next)
        {
            Node* temp=
            h1->next=h2->next;
            h2->next=h1->next->next;
            
            h1=h1->next;
            h2=h2->next;
        }
        
        
        Node* rev=reverse(head2);
        h1->next=rev;
    }
};
