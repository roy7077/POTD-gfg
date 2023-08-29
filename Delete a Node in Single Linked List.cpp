/*You are required to complete below method*/
Node* deleteNode(Node *head,int x)
{
    //base case
    if(!head)
    return NULL;
    
    if(x==1)
    {
        Node* temp=head->next;
        delete head;
        return temp;
    }
    
    //recursive calls
    Node* temp=deleteNode(head->next,x-1);
    head->next=temp;
    return head;
}