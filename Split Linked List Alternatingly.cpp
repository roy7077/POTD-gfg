// Time complexity - O(N)
// Space complexity- O(1)
class Solution {
    public:
    vector<Node*> alternatingSplitList(struct Node* head) {
       Node* headE=NULL;
       Node* tailE=NULL;
       
       Node* headO=NULL;
       Node* tailO=NULL;
       
       bool flag=1;
       Node* temp=head;
       while(temp)
       {
           if(flag)
           {
               if(!headE)
               {
                   headE=temp;
                   tailE=temp;
               }
               else
               {
                   tailE->next=temp;
                   tailE=temp;
               }
           }
           else
           {
               if(!headO)
               {
                   headO=temp;
                   tailO=temp;
               }
               else
               {
                   tailO->next=temp;
                   tailO=temp;
               }
           }
           flag=(!flag);
           temp=temp->next;
       }
       
       tailE->next=NULL;
       tailO->next=NULL;
       return {headE,headO};
    }
};
