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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return head;
        ListNode* smallerHead = NULL;
        ListNode* smallerTail = NULL;
        ListNode* greaterHead = NULL;
        ListNode* greaterTail = NULL;
        ListNode* curr = head;
        while(curr != NULL){
            if(curr->val < x){
                if(smallerHead == NULL){
                    smallerHead = curr;
                    smallerTail = curr;
                } else{
                    smallerTail->next = curr;
                    smallerTail = smallerTail->next;
                }
            } else{
                if(greaterHead == NULL){
                    greaterHead = curr;
                    greaterTail = curr;
                } else{
                    greaterTail->next = curr;
                    greaterTail = greaterTail->next;
                }
            }
            curr = curr->next;
        }
        if(!greaterHead) return smallerHead;
        if(!smallerHead) return greaterHead;
        smallerTail->next = greaterHead;
        greaterTail->next = NULL;
        return smallerHead;
    }
};