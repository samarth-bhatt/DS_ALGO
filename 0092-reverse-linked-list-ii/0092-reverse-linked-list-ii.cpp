class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right){
            return head;
        }

        ListNode temp(0);
        temp.next = head;
        ListNode* prev = &temp;

        // Move 'prev' to the node just before the 'left' position.
        for(int i = 1; i < left; ++i){
            prev = prev->next;
        }

        ListNode* current = prev->next;
        ListNode* next_node = nullptr;

        // Reversing the 'left' to 'right' segment of the linked list.
        for(int i = left; i < right; ++i){
            next_node = current->next;
            current->next = next_node->next;
            next_node->next = prev->next;
            prev->next = next_node;
        }
        return temp.next;
    }
};