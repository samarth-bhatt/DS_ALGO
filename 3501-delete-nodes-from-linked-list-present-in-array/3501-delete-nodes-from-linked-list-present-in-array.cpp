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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int>present(nums.begin(), nums.end());
        if(head->next == NULL && present.count(head->val)>0){
            delete head;
            return NULL;
        }
        while(head->next != NULL && present.count(head->val)>0){
            head->val = head->next->val;
            ListNode* temp = head->next;
            head->next = head->next->next;
            delete(temp);
        }
        ListNode* curr = head;
        while(curr != NULL && curr->next != NULL){
            if(present.count(curr->next->val) > 0){
                ListNode* temp = curr->next;
                curr->next = curr->next->next;
                delete(temp);
            } else curr = curr->next;
        }
        return head;
    }
};