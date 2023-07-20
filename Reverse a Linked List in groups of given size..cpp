class Solution
{
    public:
    
    pair<node*,node*> help(node* head,int i,int k)
    {
        //base case
        if(head->next==NULL or i==1)
        {
            return {head,head->next};
        }
        
        //recursive calls
        //small calculation
        pair<node*,node*> temp=help(head->next,i-1,k);
        head->next->next=head;
        
        if(i==k)
        {
            head->next=temp.second;
        }
        
        return temp;
    }
    
    struct node *reverse (struct node *head, int k)
    { 
        node* h1=head;
        node* pre=NULL;
        bool flag=0;
        while(h1)
        {
            pair<node*,node*> p=help(h1,k,k);
            if(!flag)
            {
                pre=h1;
                head=p.first;
                flag=1;
            }
            else
            {
                pre->next=p.first;
                pre=h1;
            }
            h1=p.second;
        }
        return head;
        
    }
};
