class Solution {
    public:
    int length(Node** head)
    {
        Node* node=*(head);
        int len=0;
        while(node)
        {
            node=node->next;
            len++;
        }
        return len;
    }
    bool isLengthEven(struct Node **head) {
        return length(head)%2==0;
    }
};
