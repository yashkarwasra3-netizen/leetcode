/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
     ListNode* reversell(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* curr= head;
        ListNode* temp= curr;
        ListNode* prev= NULL;
        while(curr!=NULL){
            temp= curr->next;
            curr->next= prev;
            prev=curr;
            curr = temp;
        }
        return prev;
        }
    bool isPalindrome(ListNode* head) {
        // ListNode* curr= head;
        // ListNode* prev= NULL;
        // while(curr != NULL){
        //     ListNode* newnode= new ListNode(curr->val);
        //     newnode->next= prev;
        //     prev= newnode;
        //     curr= curr->next;
        // }
        // ListNode* temp= prev;
        // ListNode* temp2 = head;
        // while(temp != NULL && temp2 != NULL){
        //     if(temp->val != temp2->val) return false;
        //     temp=temp->next;
        //     temp2= temp2->next;
        // }
        // return true;
       
        if(head == NULL || head->next == NULL) return true;
        ListNode* slow= head;
        ListNode* fast= head;
        while(fast -> next != NULL && fast->next->next != NULL){
            slow = slow->next;
            fast= fast->next->next;
        }
        ListNode* newhead= reversell(slow->next);
        ListNode* first = head;
        ListNode* second= newhead;
        while(second != NULL){
            if(first-> val != second-> val){
                reversell(newhead);
                return false;
            }
            first=first->next;
            second= second->next;
        }
        reversell(newhead);
        return true;
    }
};