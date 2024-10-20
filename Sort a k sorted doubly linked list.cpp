class Solution {
    public:
    DLLNode *sortAKSortedDLL(DLLNode *head, int k) {
        
        priority_queue<int,vector<int>,greater<int>> pq;
        DLLNode* temp=head;
        DLLNode* h=NULL;
        DLLNode* t=NULL;
        
        int i=0;
        while(temp)
        {
            pq.push(temp->data);
            if(i>=k)
            {
                int num=pq.top();
                pq.pop();
                
                DLLNode* newNode=new DLLNode(num);
                // cout<<tempH->data<<endl;
                if(!h)
                {
                    h=newNode;
                    t=newNode;
                }
                else
                {
                    t->next=newNode;
                    newNode->prev=t;
                    t=newNode;
                }
            }
            
            temp=temp->next;
            i++;
        }
        
        while(!pq.empty())
        {
            int num=pq.top();
            pq.pop();
            
            DLLNode* newNode=new DLLNode(num);
            if(!h)
            {
                h=newNode;
                t=newNode;
            }
            else
            {
                t->next=newNode;
                newNode->prev=t;
                t=newNode;
            }
        }
        
        return h;
    }
};
