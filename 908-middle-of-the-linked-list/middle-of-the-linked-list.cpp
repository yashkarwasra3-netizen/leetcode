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
    ListNode* middleNode(ListNode* head) {
        int cnt=0;
        int k;
        ListNode* curr= head;
        while(curr != NULL){
            curr=curr->next;
            cnt++;
        }
        if(cnt%2 == 0){
            k=cnt/2+1;
        }
        else{
            k= (cnt+1)/2;
        }
        ListNode* temp=head;
        cnt=1;
        while(cnt!= k){
            temp= temp->next;
            cnt++;
        }
        return temp;
    }
};