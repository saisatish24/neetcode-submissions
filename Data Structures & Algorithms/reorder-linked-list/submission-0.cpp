// Condition	                  Where slow ends	          Main use
// fast && fast->next	                Middle	           Find middle / cycle
// fast->next && fast->next->next	 End of first half	     Split/reorder



class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* second = slow->next;
        slow->next = NULL; // detached into 2 halves

        ListNode* prev = NULL;

        while (second) {
            ListNode* next = second->next; // saving the node
            second->next = prev;
            prev = second;
            second = next;
        }

        second = prev; // second becomes head again
        ListNode* first = head;

        while (first && second) {
            ListNode* temp1 = first->next; // save next of both halves head
            ListNode* temp2 = second->next;

            first->next = second;
            second->next = temp1;

            first = temp1; // move the heads of both halves forward
            second = temp2;
        }
    }
};