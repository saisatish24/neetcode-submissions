class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* curr = head;

        while (n != 0) {
            curr = curr->next;
            n--;
        }

        
        if (curr == NULL) {
            return head->next; // means the head is to be removed
        }

        ListNode* temp = head;

        while (curr->next) {
            temp = temp->next;
            curr = curr->next;
        }

        temp->next = temp->next->next;

        return head;
    }
};