class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        int cnt = 1;
        ListNode* curr = head;

        while (curr->next != NULL) {
            cnt++;
            curr = curr->next;
        }

        if (n == cnt) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
            return head;
        }

        curr = head;
        int pos = cnt - n;
        int i = 1;

        while (i < pos) {
            curr = curr->next;
            i++;
        }

        ListNode* temp = curr->next;
        curr->next = temp->next;
        delete temp;

        return head;
    }
};