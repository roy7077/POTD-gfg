
/* Method - 1
   reverse the linked list by recursion
   Time complexity - O(N)
   Space complexity- O(N) - Recursion stack space
*/
#define ll long long
int mod=1e9+7;
class Solution
{
        public:
        Node* reverse(Node* root)
        {
            if(!root)
            return NULL;
            
            if(root->next==NULL)
            return root;
            
            Node* temp=reverse(root->next);
            root->next->next=root;
            root->next=NULL;
            return temp;
        }
        
        int binaryToDecimal(Node* head)
        {
           int ans=0;
           int power=1;
           while(head)
           {
               if(head->data)
               ans=(ans+power)%mod;
               
               power=(power*2)%mod;
               head=head->next;
           }
           return ans;
        }
        
        long long unsigned int decimalValue(Node *head)
        {
           Node* rev=reverse(head);
           Node* temp=rev;
           
           ll ans=binaryToDecimal(rev);
           return ans;
        }
};


/* Method - 2
   reverse the linked list by Iterative
   Time complexity - O(N)
   Space complexity- O(1)
*/
#define ll long long
int mod=1e9+7;
class Solution
{
        public:
        Node* reverse(Node* root)
        {
            Node* pre=NULL;
            while(root)
            {
                Node* nextRoot=root->next;
                root->next=pre;
                pre=root;
                root=nextRoot;
            }
            return pre;
        }
        
        int binaryToDecimal(Node* head)
        {
           int ans=0;
           int power=1;
           while(head)
           {
               if(head->data)
               ans=(ans+power)%mod;
               
               power=(power*2)%mod;
               head=head->next;
           }
           return ans;
        }
        
        long long unsigned int decimalValue(Node *head)
        {
           Node* rev=reverse(head);
           Node* temp=rev;
           
           ll ans=binaryToDecimal(rev);
           return ans;
        }
};