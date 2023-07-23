class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        
        int zero=0;
        int one=0;
        int two=0;
        
        Node* h1=NULL;
        Node* tail=NULL;
        
        Node* h2=head;
        while(h2)
        {
            if(h2->data==0)
            zero++;
            else if(h2->data==1)
            one++;
            else
            two++;
            
            h2=h2->next;
        }
        
        //for zero
        while(zero)
        {
            Node* newnode=new Node(0);
            if(h1==NULL)
            {
                h1=newnode;
                tail=newnode;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
            zero--;
        }
        
        //for one
        while(one)
        {
            Node* newnode=new Node(1);
            if(h1==NULL)
            {
                h1=newnode;
                tail=newnode;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
            one--;
        }
        
        //for two
        while(two)
        {
            Node* newnode=new Node(2);
            if(h1==NULL)
            {
                h1=newnode;
                tail=newnode;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
            two--;
        }
        
        return h1;
    }
};