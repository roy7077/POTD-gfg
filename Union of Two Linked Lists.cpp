class Solution
{
    public:
    
    Node* makelinkedlist(vector<int>& v)
    {
        Node* head=NULL;
        Node* tail=NULL;
        
        int pre=v[0];
        head=new Node(v[0]);
        tail=head;
        
        for(auto it:v)
        {
            if(it!=pre)
            {
                Node* newnode=new Node(it);
                tail->next=newnode;
                tail=newnode;
                
                pre=it;
            }
        }
        
        return head;
    }
    struct Node* makeUnion(struct Node* head1, struct Node* head2)
    {
        Node* h1=head1;
        Node* h2=head2;
        
        vector<int> v;
        while(h1!=NULL){
            v.push_back(h1->data);
            h1=h1->next;
            
        }
        
        while(h2!=NULL)
        {
            v.push_back(h2->data);
            h2=h2->next;
        }
        
        sort(v.begin(),v.end());
        return makelinkedlist(v);
    }
};