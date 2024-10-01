/* Multiply contents of two linked lists */
class solution {
    public:
    long long multiplyTwoLists(Node *first, Node *second) {
        long long mod = 1000000007;
        Node*temp1=first;long long number1=0;
        while(temp1!=NULL){
            number1=(number1*10+temp1->data)%mod;
            temp1=temp1->next;
        }
           Node*temp2=second;long long number2=0;
        while(temp2!=NULL){
            number2=(number2*10+temp2->data)%mod;
            temp2=temp2->next;
        }
        long long num3=(number1*number2)%mod;
        return num3%mod;
    }
};
