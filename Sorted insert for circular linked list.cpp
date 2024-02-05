// Time complexity - O(N)
// Space complexity- O(1)
class Solution
{
    public:
    Node *sortedInsert(Node* head, int data)
    {
        if(!head) 
        {
            Node *temp = new Node(data);
            temp->next = temp;
            return temp;
        }
        
        Node* h=head->next;
        Node* pre=head;
        while(h!=head)
        {
          pre=h;
          h=h->next;
        }
       
        Node* last=pre;
        h=head;
        while(1)
        {
            if(h->data>=data)
            {
                Node* newnode=new Node(data);
                pre->next=newnode;
                newnode->next=h;
                
                if(h==head)
                return newnode;
                else
                return head;
            }
            
            if(h==last)
            {
                Node* newnode=new Node(data);
                Node* nextnode=h->next;
                h->next=newnode;
                newnode->next=nextnode;
                
                return head;
            }
            
            pre=h;
            h=h->next;
        }
        return head;
    }
};