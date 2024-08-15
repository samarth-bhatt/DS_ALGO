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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* curr = list1;
        b -= a;
        --a;
        while(a--) curr = curr->next;
        ListNode* temp = curr->next;
        ListNode* temp_head = temp;
        curr->next = list2;
        while(b--) temp = temp->next;
        curr = list2;
        while(curr->next != NULL) curr = curr->next;
        curr->next = temp->next;
        delete(temp_head);
        return list1;
    }
};