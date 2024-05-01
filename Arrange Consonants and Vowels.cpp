// Time complexity - O(Length of the linked list)
// Space complexity- O(1)
class Solution
{
    public:
    struct Node* arrangeCV(Node *head)
    {
       Node* vH=NULL;
       Node* vT=NULL;
       
       Node* cH=NULL;
       Node* cT=NULL;
       
       Node* temp=head;
       while(temp)
       {
           char ch=temp->data;
           if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u')
           {
               if(vH==NULL)
               {
                   vH=temp;
                   vT=temp;
               }
               else
               {
                   vT->next=temp;
                   vT=temp;
               }
           }
           else
           {
               if(cH==NULL)
               {
                   cH=temp;
                   cT=temp;
               }
               else
               {
                   cT->next=temp;
                   cT=temp;
               }
           }
           temp=temp->next;
       }
       
       if(vT==NULL)
       return cH;
       
       if(cH==NULL)
       return vH;
       
       vT->next=cH;
       cT->next=NULL;
       return vH;
    }
};