class Solution {
    public:
    // Function to reverse a circular linked list
    Node* reverse(Node* head) {
        if (!head || !head->next || head->next == head) {
            return head;  // If list is empty or has only one node, return head
        }

        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        Node* tail = head;  // To track the last node in the original list

        // Traverse the list and reverse the links
        do {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        } while (curr != head);  // Stop when we come back to the head

        // Now 'prev' is the new head and 'tail' should point to 'prev'
        tail->next = prev;

        return prev;  // Return the new head
    }

    // Function to delete a node with a given key
    Node* deleteNode(Node* head, int key) {
        if (!head) return NULL;  // If list is empty, return NULL

        Node* curr = head;
        Node* prev = NULL;

        // If the node to be deleted is the head
        if (head->data == key) {
            // If the list has only one node
            if (head->next == head) {
                delete head;
                return NULL;
            }

            // Traverse to the last node to update its next pointer
            Node* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }

            // Remove the head node and update links
            Node* newHead = head->next;
            delete head;
            tail->next = newHead;
            return newHead;
        }

        // Traverse the list to find the node with the key
        do {
            prev = curr;
            curr = curr->next;
            if (curr->data == key) {
                prev->next = curr->next;
                delete curr;
                return head;  // Return the original head after deletion
            }
        } while (curr != head);

        return head;  // If key not found, return the original head
    }
};
