// Time complexity - O(N+M)
// Space complexity- O(max(N,M))
class Solution
{
    public:
    Node* reverse(Node* root)
    {
        //base case
        if(root==NULL)
        return NULL;
        
        if(root->next==NULL)
        return root;
        
        //recursive calls
        Node* temp=reverse(root->next);
        root->next->next=root;
        root->next=NULL;
        return temp;
    }

    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        Node* i=reverse(first);
        Node* j=reverse(second);
        
        Node* head=NULL;
        Node* tail=NULL;
        int c=0;
        while(i and j)
        {
            int sum=c+(i->data)+(j->data);
            int first=sum/10;
            int last=sum%10;
            c=first;
            
            Node* newnode=new Node(last);
            if(head==NULL)
            {
                head=newnode;
                tail=head;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
            i=i->next;
            j=j->next;
        }
        
        while(i)
        {
            int sum=c+i->data;
            int first=sum/10;
            int last=sum%10;
            c=first;
            
            Node* newnode=new Node(last);
            if(head==NULL)
            {
                head=newnode;
                tail=head;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
            i=i->next;
        }
        
        while(j)
        {
            int sum=c+j->data;
            int first=sum/10;
            int last=sum%10;
            c=first;
            
            Node* newnode=new Node(last);
            if(head==NULL)
            {
                head=newnode;
                tail=head;
            }
            else
            {
                tail->next=newnode;
                tail=newnode;
            }
            j=j->next;
        }
        
        if(c)
        {
            Node* newnode=new Node(c);
            tail->next=newnode;
            tail=newnode;
        }
        
        head=reverse(head);
        while(head and head->data==0)
        head=head->next;
        
        if(!head)
        {
            Node* newnode=new Node(0);
            return newnode;
        }
        return head;
    }
};