//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    Node* pre=head;
    Node* curr=head->next;
    
    while(curr)
    {
        if(curr->data==pre->data)
        {
            Node* temp=curr->next;
            delete curr;
            pre->next=temp;
            curr=temp;
        }
        else
        {
            curr=curr->next;
            pre=pre->next;
        }
    }
    
    return head;
    
}